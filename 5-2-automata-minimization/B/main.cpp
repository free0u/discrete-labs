
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
#define task_name "equivalence"

typedef set<int> si;
typedef pair<si, char> mp;

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
    vector<vector<int> > g(n, vector<int> (26, -1));
    si T;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        T.insert(x - 1);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %c", &x, &y, &c);
        g[x - 1][c - 'a'] = y - 1;
    }

    int N = n;
    cin >> n >> m >> k;
    g.resize(n + N, vector<int> (26, -1));
    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        T.insert(x - 1 + N);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %c", &x, &y, &c);
        g[x - 1 + N][c - 'a'] = y - 1 + N;
    }

    n += N;

    for (size_t i = 0; i < g.size(); ++i) {
        for (char c = 0; c < 26; ++c) {
            if (g[i][c] == -1) {
                g[i][c] = n;
            }
        }
    }
    g.push_back(vector<int> (26, n));
    ++n;

    vector<si> P;
    queue<mp> Q;
    si s1, s2;
    for (int i = 0; i < n; ++i) {
        if (T.find(i) != T.end()) {
            s1.insert(i);
        } else {
            s2.insert(i);
        }
    }
    P.push_back(s1);
    P.push_back(s2);
    for (int i = 0; i < 26; ++i) {
        Q.push(make_pair(s1, i));
        Q.push(make_pair(s2, i));
    }

    while (!Q.empty()) {
        vector<si> P_next;


        mp p = Q.front();
        Q.pop();
        for (vector<si>::iterator R = P.begin(); R != P.end(); ++R) {
            si r1, r2;
            for (si::iterator it = R->begin(); it != R->end(); ++it) {
                int to = g[*it][p.second];
                if (p.first.find(to) != p.first.end()) {
                    r1.insert(*it);
                } else {
                    r2.insert(*it);
                }
            }
            if (!r1.empty() && !r2.empty()) {
                P_next.push_back(r1);
                P_next.push_back(r2);
                Q.push(make_pair(r1, p.second));
                Q.push(make_pair(r2, p.second));
            } else {
                P_next.push_back(*R);
            }
        }
        P = P_next;
    }


    for (vector<si>::iterator R = P.begin(); R != P.end(); ++R) {
        if (R->find(0) != R->end() &&
                R->find(N) != R->end()) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
