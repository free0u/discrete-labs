#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <cassert>

using namespace std;
#define task_name "minimization"

typedef set<int> si;
typedef pair<si, char> mp;

#define ALP_SIZE 26

vector<vector<int> > g;
vector<bool> used;

void dfs(int v) {
    used[v] = true;
    for (int c = 0; c < ALP_SIZE; ++c) {
        int to = g[v][c];
        if (to != -1 && !used[to]) {
            dfs(to);
        }
    }
}

int main() {
    //freopen("output.txt", "w", stdout);

    srand(time(0));
    int N = 3;

    int cnt_e;


    int T1, T2;
    while (true) {
        cnt_e = 0;
        g.assign(N, vector<int> (ALP_SIZE, -1));

        T1 = rand() % N;
        T2 = rand() % N;

        for (int i = 0; i < N; ++i) {
            for (int c = 0; c < 4; ++c) {
                if (rand() & 1) {
                    g[i][c] = rand() % N;
                    ++cnt_e;
                }
            }
        }
        used.assign(N, false);
        dfs(0);
        if (used[T1] || used[T2]) break;
    }


    printf("%d %d %d\n", N, cnt_e, 2);
    cout << T1 + 1 << " " << T2 + 1 << endl;

    for (int i = 0; i < N; ++i) {
        for (int c = 0; c < ALP_SIZE; ++c) {
            if (g[i][c] != -1) {
                printf("%d %d %c\n", i + 1, g[i][c] + 1, (char)('a' + c));
            }
        }
    }



    return 0;
}
