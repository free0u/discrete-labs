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

//void out() {
//    for (size_t j = 0; j < dp.size(); ++j) {
//        printf("%c\n", (char)('A' + j));
//        for (size_t i = 0; i < dp[j].size(); ++i) {
//            for (size_t g = 0; g < dp[j][i].size(); ++g) {
//                printf("%2lld ", dp[j][i][g]);
//            }
//            cout << endl;
//        }
//    }
//}

//ll mod(ll x) {
//    return x % 1000000007;
//}

#define ALP_SIZE 26

int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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

        s = s.substr(5, l - 5);
        if (s.length() == 2) {
            is_term[s[0] - 'A'] = true;
            is_term[s[1] - 'A'] = true;
        }
        a[from - 'A'].push_back(s);

    }

    string pattern;
    cin >> pattern;
    int len = pattern.size();

    dp.assign(ALP_SIZE, vector<vector<ll> > (len, vector<ll> (len)));

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < ALP_SIZE; ++j) {
            for (size_t g = 0; g < a[j].size(); ++g) {
                int from = j;

                if (a[j][g].length() == 1 && a[j][g][0] == pattern[i]) {
                    dp[from][i][i]++;
                }
            }
        }
    }

    for (int len_m = 1; len_m <= len; ++len_m) {
        for (int i = 0; i < len; ++i) {
            int j = i + len_m - 1;
            if (j >= len) continue;

            for (int d = i; d < j; ++d) {
                for (int term = 0; term < ALP_SIZE; ++term) {
                    if (!is_term[term]) continue;
                    for (size_t k = 0; k < a[term].size(); ++k) {
                        if (a[term][k].length() != 2) continue;

                        dp[term][i][j] = (dp[term][i][j] + (dp[a[term][k][0] - 'A'][i][d]) *
                                                              (dp[a[term][k][1] - 'A'][d + 1][j])) % 1000000007;
                    }
                }
            }
        }
    }

//    out();

    cout << dp[start[0] - 'A'][0][len - 1];

    return 0;
}
