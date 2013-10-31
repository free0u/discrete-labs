#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "isomorphism"

struct fsm {
    int n, m, k;
    vector<vector<int> > g;
    vector<bool> T, used;
    vector<int> ids, from_ids;
    int counter;

    fsm(int n, int m, int k) : n(n), m(m), k(k) {
        g.assign(n, vector<int> (26, -1));
        T.assign(n, false);
        used.assign(n, false);
        ids.resize(n);
        from_ids.resize(n);
        counter = -1;
    }

    void add(int from, int to, char c) {
        g[from][c] = to;
    }

    void calc_id(int v) {
        from_ids[++counter] = v;
        ids[v] = counter;
        used[v] = true;
        for (size_t i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (to != -1 && !used[to]) {
                calc_id(to);
            }
        }
    }

    bool equal(fsm const& o) {
        if (n != o.n || m != o.m || k != o.k) return false;
        for (int i = 0; i < n; ++i) {
            int p = ids[i];
            p = o.from_ids[p];
            if (T[i] != o.T[p]) return false;
        }
        for (int i = 0; i < n; ++i) {
            int p = ids[i];
            p = o.from_ids[p];
            for (int j = 0; j < 26; ++j) {
                int t1 = g[i][j];
                int t2 = o.g[p][j];

                if (t1 != -1 && t2 != -1) {
                    t1 = ids[t1];
                    t2 = o.ids[t2];
                }
                if (t1 != t2) return false;
            }
        }
        return true;
    }
};

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
    fsm m1(n, m, k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        m1.T[x - 1] = true;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %c", &x, &y, &c);
        m1.add(x - 1, y - 1, c - 'a');
    }

    cin >> n >> m >> k;
    fsm m2(n, m, k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        m2.T[x - 1] = true;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %c", &x, &y, &c);
        m2.add(x - 1, y - 1, c - 'a');
    }

    m1.calc_id(0);
    m2.calc_id(0);

    cout << (m1.equal(m2) ? "YES" : "NO");

    return 0;
}
