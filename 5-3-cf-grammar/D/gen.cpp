#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
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


int rr(int x) {
    return abs(rand()) % x;
}

int main() {
//#ifndef HOME_free0u
//    freopen(task_name".in", "r", stdin);
//    freopen(task_name".out", "w", stdout);
//    #define ALP_SIZE 26
//#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #define ALP_SIZE 26
//#endif

    srand(time(0));

    int N = 5;
    int ALP_SIZE = 5;

    cout << N << " ";
    cout << (char)('A' + rr(ALP_SIZE)) << endl;
    for (int i = 0; i < N; ++i) {
        cout << (char)('A' + rr(ALP_SIZE)) << " -> ";

        if (rand() & 1) {
            cout << (char)('a' + rr(1));
            //cout << 'a';
        } else
        {
            cout << (char)('A' + rr(ALP_SIZE));
            cout << (char)('A' + rr(ALP_SIZE));
        }

        cout << endl;
    }

    int len = rr(7) + 1;
    for (int i = 0; i < len; ++i) {
        cout << (char)('a' + rr(2));
    }

    cout << endl;


    return 0;
}
