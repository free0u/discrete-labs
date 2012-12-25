#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
#define task_name "minimax"

const int inf = 1e9 + 31;
int n, source_n;
vector< vector<int> > c, f, data;
vector<int> p, d;
deque<int> q;

int find_flow(int u, int flow) {
    if (u == n - 1) {
        return flow;
    }
    if (flow == 0) {
        return 0;
    }
    while (p[u] < n) {
        int i = p[u]++;
        if (d[i] == d[u] + 1) {
            int res = find_flow(i, min(flow, c[u][i] - f[u][i]));
            if (res != 0) {
                f[u][i] += res;
                f[i][u] -= res;
                return res;
            }
        }
    }
    return 0;
}


bool have_path() {
	d.assign(d.size(), inf);
	q.clear();
	d[0] = 0;
	q.push_front(0);
	while (!q.empty()) {
		int cur = q.front(); q.pop_front();
		for (int i = 0; i < n; ++i) {
			if (d[i] > d[cur] + 1 && c[cur][i] - f[cur][i] > 0) {
				d[i] = d[cur] + 1;
				q.push_back(i);
			}
		}
	}
	return d[n - 1] != inf;
}

bool have_matching(int v) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = f[i][j] = 0;
        }
    }
 
    for (int i = 0; i < source_n; ++i) {
        for (int j = 0; j < source_n; ++j) {
            if (data[i][j] >= v) {
                int u = i + 1, v = j + source_n + 1;
                c[0][u] = 1;
                c[u][v] = 1;
                c[v][n - 1] = 1;
            }
        }
    }
 
    int ans = 0;
    while (have_path()) {
		p.assign(p.size(), 0);
		while (true) {
            int flow = find_flow(0, inf);
            if (flow == 0) {
                break;
            }
            ans += flow;
        }
    }
    return ans == source_n;
}

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> source_n;

	n = 2 + 2 * source_n;

	p.resize(n);
	d.resize(n);
	c.assign(n, vector<int> (n));
	f.assign(n, vector<int> (n));
	data.assign(n, vector<int> (source_n));

	for (int i = 0; i < source_n; ++i) {
		for (int j = 0; j < source_n; ++j) {
			int u = i + 1;
			int v = j + source_n + 1;
			scanf("%d", &data[i][j]);
			c[0][u] = 1;
			c[u][v] = 1;
			c[v][n - 1];
		}
	}
	int l = 0, r = 1e8;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (have_matching(m)) {
			l = m;
		} else
		{
			r = m;
		}
	}
	cout << l;
	return 0;
}