#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "problem2"

int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    int n, m, k, x, y;
    char c;
    cin >> n >> m >> k;
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

    vector<bool> R1(n), R2(n);
    R1[0] = true;
    for (size_t i = 0; i < s.length(); ++i) {
        int c = s[i] - 'a';
        for (size_t j = 0; j < R1.size(); ++j) {
            if (!R1[j]) continue;
            for (size_t g = 0; g < a[j][c].size(); ++g) {
                R2[a[j][c][g]] = true;
            }
        }
        R1 = R2;
        R2.assign(n, false);
    }

    for (size_t i = 0; i < T.size(); ++i) {
        if (R1[T[i]]) {
            cout << "Accepts";
            return 0;
        }
    }
    cout << "Rejects";
    return 0;
}
