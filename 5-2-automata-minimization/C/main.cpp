#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <cassert>
#include <queue>

using namespace std;
#define task_name "minimization"

typedef set<int> si;
typedef pair<si, char> mp;

#define ALP_SIZE 26

vector<bool> used;
vector<vector<int> > g;
typedef pair<int, int> pii;

void dfs(int v) {
    used[v] = true;
    for (int c = 0; c < ALP_SIZE; ++c) {
        int to = g[v][c];
        if (to != -1 && !used[to]) {
            dfs(to);
        }
    }
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
    g.assign(n, vector<int> (ALP_SIZE, -1));
    si T;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        T.insert(x - 1);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %c", &x, &y, &c);
        g[x - 1][c - 'a'] = y - 1;
    }

    for (size_t i = 0; i < g.size(); ++i) {
        for (char c = 0; c < ALP_SIZE; ++c) {
            if (g[i][c] == -1) {
                g[i][c] = n;
            }
        }
    }
    g.push_back(vector<int> (ALP_SIZE, n));
    ++n;

    used.assign(n, false);
    dfs(0);

    vector<int> ids(n, -1);
    int cl = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) continue;
        ids[i] = cl++;
    }

    vector<vector<int> > gu(cl, vector<int> (ALP_SIZE, -1));
    si Tu;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) continue;
        for (int c = 0; c < ALP_SIZE; ++c) {
            int to = g[i][c];
            if (!used[to]) continue;
            gu[ids[i]][c] = ids[to];
            if (T.find(i) != T.end()) {
                Tu.insert(ids[i]);
            }
        }
    }

    g = gu;
    T = Tu;
    n = g.size();

    if (T.empty()) {
        cout << "1 0 1\n1";
        return 0;
    }

    vector<vector<vector<int> > > par(n, vector<vector<int> > (ALP_SIZE));
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < ALP_SIZE; ++c) {
            par[g[i][c]][c].push_back(i);
        }
    }

    vector<vector<bool> > a(n, vector<bool> (n, false));
    queue<pii> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool found_i = T.find(i) != T.end();
            bool found_j = T.find(j) != T.end();
            if ((found_i && !found_j) ||
                (!found_i && found_j)) {
                a[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        int u = p.first;
        int v = p.second;
        for (int c = 0; c < ALP_SIZE; ++c) {
            for (size_t i = 0; i < par[u][c].size(); ++i) {
                for (size_t j = 0; j < par[v][c].size(); ++j) {
                    int t = par[u][c][i];
                    int k = par[v][c][j];
                    if (a[t][k]) continue;
                    a[t][k] = true;
                    q.push(make_pair(t, k));
                }
            }
        }
    }

    vector<si> P;
    vector<bool> in_class(n, false);
    for (int i = 0; i < n; ++i) {
        if (in_class[i]) continue;

        si new_class;
        new_class.insert(i);
        in_class[i] = true;
        for (int j = 0; j < n; ++j) {
            if (!a[i][j] && !in_class[j]) {
                new_class.insert(j);
                in_class[j] = true;
            }
        }
        P.push_back(new_class);
    }

    for (size_t i = 0; i < P.size(); ++i) {
        if (P[i].find(n - 1) != P[i].end()) {
            swap(P[i], P.back());
            break;
        }
    }

    ids.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        for (size_t j = 0; j < P.size(); ++j) {
            if (P[j].find(i) != P[j].end()) {
                ids[i] = j;
            }
        }
    }

    si Tf;
    for (si::iterator it = T.begin(); it != T.end(); ++it) {
        Tf.insert(ids[*it]);
    }

    vector<vector<int> > gf(P.size(), vector<int> (ALP_SIZE, -1));
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < ALP_SIZE; ++c) {
            int to = g[i][c];
            gf[ids[i]][c] = ids[to];
        }
    }

    g = gf;
    T = Tf;
    n = g.size();

    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < ALP_SIZE; ++c) {
            if (g[i][c] == n - 1) {
                g[i][c] = -1;
            }
        }
    }
    g.pop_back();
    --n;


    int cnt_edges = 0;
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < ALP_SIZE; ++c) {
            if (g[i][c] != -1) {
                ++cnt_edges;
            }
        }
    }

    printf("%d %d %d\n", n, cnt_edges, (int)T.size());
    for (si::iterator it = T.begin(); it != T.end(); ++it) {
        printf("%d ", *it + 1);
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < ALP_SIZE; ++c) {
            if (g[i][c] != -1) {
                printf("%d %d %c\n", i + 1, g[i][c] + 1, (char)('a' + c));
            }
        }
    }

//    for (size_t i = 0; i < P.size(); ++i) {
//        for (si::iterator it = P[i].begin(); it != P[i].end(); ++it) cout << *it << " ";
//        cout << endl;
//    }


    return 0;
}
