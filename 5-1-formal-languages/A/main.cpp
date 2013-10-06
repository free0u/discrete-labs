#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "problem1"

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

    int cur_state = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        int next = a[cur_state][s[i] - 'a'];
        if (next == -1) {
            cout << "Rejects";
            return 0;
        }
        cur_state = next;
    }
    if (T[cur_state]) {
        cout << "Accepts";
    } else
    {
        cout << "Rejects";
    }

    return 0;
}
