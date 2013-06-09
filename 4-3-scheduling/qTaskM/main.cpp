#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <limits>
using namespace std;
#define task_name "rsumc"

vector<bool> found;
int N;
vector<vector<int> > cap, flow, cost;
vector<int> dad, dist, pi;

const int INF = numeric_limits<int>::max() / 2 - 1;

void add_edge(int s, int t, int _cap, int _cost) {
    cap[s][t] = _cap;
    cost[s][t] = _cost;
    cap[t][s] = 0;
    cost[t][s] = -_cost;
}

bool search(int source, int sink) {
    found.assign(found.size(), false);
    dist.assign(dist.size(), INF);
    dist[source] = 0;

    while (source != N) {
        int best = N;
        found[source] = true;
        for (int k = 0; k < N; k++) {
        if (found[k]) continue;
        if (flow[k][source] != 0) {
            int val = dist[source] + pi[source] - pi[k] - cost[k][source];
            if (dist[k] > val) {
            dist[k] = val;
            dad[k] = source;
            }
        }
        if (flow[source][k] < cap[source][k]) {
            int val = dist[source] + pi[source] - pi[k] + cost[source][k];
            if (dist[k] > val) {
            dist[k] = val;
            dad[k] = source;
            }
        }

        if (dist[k] < dist[best]) best = k;
        }
        source = best;
    }
    for (int k = 0; k < N; k++)
        pi[k] = min(pi[k] + dist[k], INF);
    return found[sink];
}


pair<int, int> getMaxFlow(int source, int sink) {
    N = cap.size();
    found.assign(N, false);
    flow.assign(N, vector<int>(N, 0));
    dist.assign(N + 1, 0);
    dad.assign(N, 0);
    pi.assign(N, 0);

    int totflow = 0, totcost = 0;
    while (search(source, sink)) {
        int amt = INF;
        for (int x = sink; x != source; x = dad[x])
        amt = min(amt, flow[x][dad[x]] != 0 ? flow[x][dad[x]] :
                       cap[dad[x]][x] - flow[dad[x]][x]);
        for (int x = sink; x != source; x = dad[x]) {
        if (flow[x][dad[x]] != 0) {
            flow[x][dad[x]] -= amt;
            totcost -= amt * cost[x][dad[x]];
        } else {
            flow[dad[x]][x] += amt;
            totcost += amt * cost[dad[x]][x];
        }
        }
        totflow += amt;
    }

    return make_pair(totflow, totcost);
}

int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<vector<int> > data(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &data[i][j]);
        }
    }

    int kv = n * m + n + 2;
    cap.assign(kv, vector<int> (kv, 0));
    cost.assign(kv, vector<int> (kv, 0));
    for (int i = 0; i < n; ++i) {
        add_edge(0, i + 1, 1, 0);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                add_edge(i + 1, n + j * n + k + 2, 1, data[i][j] * (k + 1));
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int k = 0; k < n; k++) {
            add_edge(n + j * n + k + 2, kv - 1, 1, 0);
        }
    }

    pair<int, int> pr = getMaxFlow(0, kv - 1);

    vector<vector<int> > ans(m, vector<int> (n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < kv; ++j) {
            if (flow[i + 1][j] == 1) {
                int to = j - n - 2;
                ans[to / n][to % n] = i + 1;
            }
        }
    }

    cout << pr.second << endl;
    for (int i = 0; i < m; ++i) {
        int j = n - 1;
        while (j >= 0 && ans[i][j] == 0) {
            --j;
        }
        printf("%d ", j + 1);
        while (j >= 0) {
            printf("%d ", ans[i][j--]);
        }
        cout << endl;
    }

    return 0;
}
