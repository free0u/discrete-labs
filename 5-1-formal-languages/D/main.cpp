#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "problem4"

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
    vector<vector<int> > a(n, vector<int> (26, -1));
    vector<bool> T(n);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        --x;
        T[x] = true;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %c", &x, &y, &c);
        --x; --y; c -= 'a';
        a[x][c] = y;
    }

    vector<vector<int> > dp(l + 1, vector<int> (n));
    for (int i = 0; i < n; ++i) {
        dp[0][i] = (T[i] ? 1 : 0);
    }

    for (int i = 1; i <= l; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int g = 0; g < 26; ++g) {
                if (a[j][g] == -1) continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][a[j][g]]) % mod;
            }
        }
    }

    cout << dp[l][0];
    return 0;
}
