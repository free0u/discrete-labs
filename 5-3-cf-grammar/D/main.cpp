
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "nfc"

typedef long long ll;

vector<vector<vector<ll> > > dp;

void out() {
    for (size_t j = 0; j < dp.size(); ++j) {
        printf("%c\n", (char)('A' + j));
        for (size_t i = 0; i < dp[j].size(); ++i) {
            for (size_t g = 0; g < dp[j][i].size(); ++g) {
                printf("%2lld ", dp[j][i][g]);
            }
            cout << endl;
        }
    }
}

ll mod(ll x) {
    return x % 1000000007;
}

int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
    #define ALP_SIZE 26
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #define ALP_SIZE 26
#endif


    vector<bool> is_term(ALP_SIZE, false);
    string start, s;
    int n;
    cin >> n >> start; getchar();
    vector<vector<string> > a(ALP_SIZE);
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

    string pattern;
    cin >> pattern;
    int len = pattern.size();

    dp.assign(ALP_SIZE, vector<vector<ll> > (len, vector<ll> (len)));

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < ALP_SIZE; ++j) {
            for (size_t g = 0; g < a[j].size(); ++g) {
                int from = j;
                string to = a[j][g];

                if (to.length() == 1 && to[0] == pattern[i]) {
                    dp[from][i][i]++;
                }
            }
        }
    }

    for (int len_m = 1; len_m <= len; ++len_m) {
        for (int i = 0; i < len; ++i) {
            //for (int j = i + 1; j < len; ++j) {
            {
                int j = i + len_m - 1;
                if (j >= len) continue;
//                printf("\ni = %d; j = %d\n", i, j);
//                out();


                if (j - i == 3) {
                    int z = 0;
                    (void)z;
                }

                for (int d = i; d < j; ++d) {
                for (int term = 0; term < ALP_SIZE; ++term) {
                    for (size_t k = 0; k < a[term].size(); ++k) {
                        string to = a[term][k];
                        if (to.length() != 2) continue;

                        dp[term][i][j] = mod(dp[term][i][j] + (dp[to[0] - 'A'][i][d]) *
                                                              (dp[to[1] - 'A'][d + 1][j]));

                        }
                    }
                }
            }
        }
    }

//    out();

    cout << dp[start[0] - 'A'][0][len - 1];

    return 0;
}
