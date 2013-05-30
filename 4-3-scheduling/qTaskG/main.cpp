
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "r2cmax"

const int inf = 1e9 + 31;

int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> p1(n), p2(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d ", &p1[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d ", &p2[i]);
    }

    int max_time = 1;
    for (size_t i = 0; i < p1.size(); ++i) {
        max_time += p1[i];
    }
    vector<int> dp0(max_time + 1, inf);
    vector<int> dp1(max_time + 1, inf);

    vector<int> * d0 = &dp0;
    vector<int> * d1 = &dp1;

    (*d0)[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < max_time; ++j) {
            (*d1)[j] = inf;
            if (j - p1[i] >= 0) {
                (*d1)[j] = min((*d1)[j], (*d0)[j - p1[i]]);
            }
            (*d1)[j] = min((*d1)[j], (*d0)[j] + p2[i]);
        }
        swap(d0, d1);
    }

    int ans = inf;
    for (int i = 0; i < max_time; ++i) {
        ans = min(ans, max(i, (*d0)[i]));
    }

    cout << ans << endl;
    //
    return 0;
}
