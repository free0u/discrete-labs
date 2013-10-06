#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "problem3"

struct edge {
    int to;
    char c;
    edge(int to, char c) : to(to), c(c) {}
};

vector<bool> good_vertexes;
vector<vector<edge> > a, aT;
vector<bool> T;
const int mod = 1e9 + 7;


void dfs1(int v) {
    good_vertexes[v] = true;
    for (size_t i = 0; i < aT[v].size(); ++i) {
        int to = aT[v][i].to;
        if (!good_vertexes[to]) {
            dfs1(to);
        }
    }
}

vector<int> cl;
bool dfs2(int v) {
    cl[v] = 1;
    for (size_t i = 0; i < a[v].size(); ++i) {
        int to = a[v][i].to;
        if (!good_vertexes[to]) continue;
        if (cl[to] == 0) {
            if (dfs2(to)) return true;
        } else if (cl[to] == 1)
        {
            return true;
        }
    }
    cl[v] = 2;
    return false;
}

int calc(int v) {
    int ret = (T[v] ? 1 : 0);

    for (size_t i = 0; i < a[v].size(); ++i) {
        int to = a[v][i].to;
        if (!good_vertexes[to]) continue;
        ret = (ret + calc(to)) % mod;
    }

    return ret;
}

int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, k, x, y;
    char c;
    cin >> n >> m >> k;

    a.resize(n);
    aT.resize(n);
    T.resize(n);

    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        --x;
        T[x] = true;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %c", &x, &y, &c);
        --x; --y; c -= 'a';
        a[x].push_back(edge(y, c));
        aT[y].push_back(edge(x, c));
    }

    good_vertexes.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!T[i]) continue;

        if (!good_vertexes[i]) {
            dfs1(i);
        }
    }

    cl.resize(n);
    bool cycle = dfs2(0);
    if (cycle) {
        cout << -1;
        return 0;
    }

    cout << calc(0);
    return 0;
}
