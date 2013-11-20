#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "useless"

int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    vector<bool> is_term(26, false);
    string start, s;
    int n;
    cin >> n >> start; getchar();
    vector<vector<string> > a(26);
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        char from = s[0];
        is_term[from - 'A'] = true;
        size_t l = s.length();
        if (l > 4)
            s = s.substr(5, l - 5);
        else
            s = "";
        a[from - 'A'].push_back(s);

        for (size_t j = 0; j < s.size(); ++j) {
            if (s[j] >= 'A' && s[j] <= 'Z') {
                is_term[s[j] - 'A'] = true;
            }
        }
    }

    vector<bool> is_generating(26, false);
    for (int i = 0; i < 26; ++i) {
        for (size_t j = 0; j < a[i].size(); ++j) {
            int from = i;
            string to = a[i][j];

            bool f = true;
            for (size_t k = 0; k < to.size(); ++k) {
                if (to[k] >= 'A' && to[k] <= 'Z') {
                    f = false;
                    break;
                }
            }

            if (f) {
                is_generating[from] = true;
            }

        }
    }

    bool changed = true;
    while (changed) {
        changed = false;

        for (int i = 0; i < 26; ++i) {
            if (is_generating[i]) continue;

            for (size_t j = 0; j < a[i].size(); ++j) {
                int from = i;
                string to = a[i][j];

                bool f = true;
                for (size_t k = 0; k < to.size(); ++k) {
                    if (to[k] >= 'A' && to[k] <= 'Z') {
                        if (!is_generating[to[k] - 'A']) {
                            f = false;
                            break;
                        }
                    }
                }

                if (f) {
                    is_generating[from] = true;
                    changed = true;
                }
            }
        }
    }


    vector<bool> is_reachable(26, false);
    is_reachable[start[0] - 'A'] = true;

    changed = true;
    while (changed) {
        changed = false;

        for (int i = 0; i < 26; ++i) {
            if (!is_reachable[i]) continue;

            for (size_t j = 0; j < a[i].size(); ++j) {
                string to = a[i][j];

                for (size_t k = 0; k < to.size(); ++k) {
                    if (to[k] >= 'A' && to[k] <= 'Z') {
                        if (!is_reachable[to[k] - 'A']) {
                            is_reachable[to[k] - 'A'] = true;
                            changed = true;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (is_term[i] && (!is_reachable[i] || ! is_generating[i])) {
            printf("%c ", 'A' + i);
        }
    }

    return 0;
}
