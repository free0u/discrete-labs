#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "automaton"

vector<vector<vector<int> > > g;
string st;

bool check(string const& s) {
    vector<bool> R1(27), R2(27);
    R1[st[0] - 'A'] = true;
    for (size_t i = 0; i < s.length(); ++i) {
        int c = s[i] - 'a';
        for (size_t j = 0; j < R1.size(); ++j) {
            if (!R1[j]) continue;
            for (size_t k = 0; k < g[j][c].size(); ++k) {
                R2[g[j][c][k]] = true;
            }
        }
        R1 = R2;
        R2.assign(27, false);
    }
    return R1[26];
}

int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;

    cin >> n >> st;

    g.assign(27, vector<vector<int> > (26));

    string from, to, delim;
    for (int i = 0; i < n; ++i) {
        cin >> from >> delim >> to;
        if (to.size() == 1) {
            g[from[0] - 'A'][to[0] - 'a'].push_back(26);
        } else {
            g[from[0] - 'A'][to[0] - 'a'].push_back(to[1] - 'A');
        }
    }

    int m;
    cin >> m;
    string p;
    for (int i = 0; i < m; ++i) {
        cin >> p;
        printf("%s\n", check(p) ? "yes" : "no");
    }

    return 0;
}
