
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;
#define task_name "pintreep1l"

vector<int> d;
vector<vector<int> > g, rg;

void dfs(int v) {
    int ind;
    for (size_t i = 0; i < rg[v].size(); ++i) {
        ind = rg[v][i];
        d[ind] = min(d[ind], d[v] - 1);
        dfs(ind);
    }
}

bool my_comp(const int a, const int b) {
    return d[a] < d[b];
}

int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, a, b;
    cin >> n >> m;
    d.resize(n);
    vector<int> d_old(n), id;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &d[i]);
        d_old[i] = d[i];
        id.push_back(i);
    }

    g.resize(n);
    rg.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &a, &b);
        --a; --b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    int p;
    for (int i = 0; i < n; ++i) {
        if (g[i].empty()) {
            p = i;
            break;
        }
    }
    dfs(p);

    sort(id.begin(), id.end(), my_comp);

    int f = 0;
    vector<int> rev_i(n), start_time(n), tt(n + 1);
    for (int i = 0; i < n; i++) {
        int ind = id[i];
        int time = max(rev_i[ind], f);

        if (!g[ind].empty()) {
            int ind2 = g[ind][0];
            if (rev_i[ind2] < time + 1)
                rev_i[ind2] = time + 1;
        }

        start_time[ind] = time;
        tt[time]++;
        if (tt[time] == m) {
            for (f = time + 1; tt[f] == m; ++f);
        }
    }

    int ans = std::numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
        ans = max(ans, start_time[i] - d_old[i]);
    }
    cout << ans + 1 << endl;
    for (int i = 0; i < n; i++) {
        printf("%d ", start_time[i]);
    }

    return 0;
}
