#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;
#define task_name "problem5"

typedef set<int> S;

int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int mod = 1e9 + 7;

    int n, m, k, x, y, l;
    char c;
    cin >> n >> m >> k >> l;
    vector<vector<vector<int> > > a(n, vector<vector<int> > (26));
    vector<bool> T(n);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        --x;
        T[x] = true;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %c", &x, &y, &c);
        --x; --y; c -= 'a';
        a[x][c].push_back(y);
    }

    queue<S> q;
    map<S, vector<S> > au;
    map<S, bool> used;

    S temp_set;
    temp_set.insert(0);
    q.push(temp_set);
    used[temp_set] = true;

    while (!q.empty()) {
        S qd = q.front();
        q.pop();
        for (int ch = 0; ch < 26; ++ch) {
            S pd;
            for (S::iterator it = qd.begin(); it != qd.end(); ++it) {
                for (size_t j = 0; j < a[*it][ch].size(); ++j) {
                    int t = a[*it][ch][j];
                    if (t != -1) {
                        pd.insert(t);
                    }
                }
            }
            if (!pd.empty()) {
                if (!used[pd]) {
                    used[pd] = true;
                    q.push(pd);
                }
                au[qd].push_back(pd);
            }
        }
    }


    set<S> vertexes;
    for (map<S, vector<S> >::iterator it = au.begin(); it != au.end(); ++it) {
        S vertex = it->first;
        vertexes.insert(vertex);
        vector<S> to = it->second;
        for (size_t i = 0; i < to.size(); ++i) {
            vertexes.insert(to[i]);
        }
    }

    map<S, vector<int> > dp;
    for (set<S>::iterator it = vertexes.begin(); it != vertexes.end(); ++it) {
        S vertex = *it;

        dp[vertex].assign(l + 1, 0);

        bool term = false;

        for (size_t i = 0; i < T.size(); ++i) {
            if (!T[i]) continue;
            if (vertex.find(i) != vertex.end()) {
                term = true;
                break;
            }
        }
        if (term) {
            dp[vertex][0] = 1;
        }
    }

    for (int i = 1; i <= l; ++i) {
        for (map<S, vector<S> >::iterator it = au.begin(); it != au.end(); ++it) {
            S vertex = it->first;
            vector<S> to = it->second;
            for (size_t j = 0; j < to.size(); ++j) {
                // edge : vertex -> to[j]
                dp[vertex][i] = (dp[vertex][i] + dp[to[j]][i - 1]) % mod;
            }
        }
    }

    cout << dp[temp_set][l];

    return 0;
}
