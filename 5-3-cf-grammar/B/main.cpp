#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "epsilon"

int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    string s;
    int n;
    cin >> n >> s; getchar();
    vector<vector<string> > a(26);
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        char from = s[0];
        size_t l = s.length();
        if (l > 4)
            s = s.substr(5, l - 5);
        else
            s = "";
        a[from - 'A'].push_back(s);
    }

    vector<bool> ans(26, false);
    for (int i = 0; i < 26; ++i) {
        for (size_t j = 0; j < a[i].size(); ++j) {
            if (a[i][j].empty()) {
                ans[i] = true;
            }
        }
    }

    bool changed = true;
    while (changed) {
        changed = false;

        for (int i = 0; i < 26; ++i) {
            if (ans[i]) continue;
            for (size_t j = 0; j < a[i].size(); ++j) {
                bool is_eps = true;
                for (size_t k = 0; k < a[i][j].size(); ++k) {
                    char c = a[i][j][k];
                    if ((c >= 'a' && c <= 'z') || !ans[c - 'A']) {
                        is_eps = false;
                        break;
                    }
                }
                if (is_eps) {
                    ans[i] = true;
                    changed = true;
                }
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (ans[i]) {
            printf("%c ", 'A' + i);
        }
    }

    return 0;
}
