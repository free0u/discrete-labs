#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "p1p1sumu"


int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    long long d1, d2, A, B, C, D;
    long long d3;
    cin >> n >> d1 >> d2 >> A >> B >> C >> D;

    vector<int> calc(n + 2);

    if (d1 != 0)
        ++calc[d1 > n ? n + 1 : d1];
    if (d2 != 0)
        ++calc[d2 > n ? n + 1 : d2];


    for (int i = 2; i < n; i++) {
        d3 = (A * d1 + B * d2 + C) % D;

        if (d3 != 0)
            ++calc[d3 > n ? n + 1 : d3];

        d1 = d2;
        d2 = d3;
    }

    int done = 0;
    int t = 0;
    for (int i = 0; i < calc.size(); i++) {
        for (int j = 0; j < calc[i]; j++) {
            ++t;
            if (i >= t) ++done;
        }
    }

    cout << done;

    return 0;
}
