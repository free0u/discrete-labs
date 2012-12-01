#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
#define task_name "circulation"

const long long inf = 1e16 + 31;

struct edge {
	int id, min_cap, cap;
	edge() {}
	edge(int min_cap, int cap, int id) : 
		min_cap(min_cap), cap(cap), id(id)
	{
	}
};


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
	n += 2;

	vector< vector< vector<edge> > > data(n, vector< vector<edge> > (n));
	vector< vector<int> > sum_cap(n, vector<int> (n));
	vector< vector<int> > c(n, vector<int> (n));

	int from, to, l, w;
	edge e;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d %d", &from, &to, &l, &w);
		e = edge(l, w, i);
		data[from][to].push_back(e);
		sum_cap[from][to] += l;

		c[0][to] += e.min_cap;
		c[from][to] += e.cap - e.min_cap;
		c[from][n - 1] += e.min_cap;
	}

	vector< vector<int> > f(n, vector<int> (n));
	while (true) {

		// find path
		vector<int> from(n, -1);
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int i = 0; i < n; ++i) {
				if (from[i] == -1 && (c[v][i] - f[v][i]) > 0) {
					q.push(i);
					from[i] = v;
				}
			}
		}

		if (from[n - 1] == -1) { // not found path
			break;
		}

		int cf = inf;
		for (int cur = n - 1; cur != 0; ) {
			int prev = from[cur];
			cf = min(cf, c[prev][cur] - f[prev][cur]);
			cur = prev;
		}

		for (int cur = n - 1; cur != 0; ) {
			int prev = from[cur];
			f[prev][cur] += cf;
			f[cur][prev] = -f[prev][cur];
			cur = prev;
		}
	}

	bool have_cir = true;
	for (int i = 0; i < n; ++i) {
		if (f[0][i] < c[0][i]) {
			have_cir = false;
		}
	}

	if (!have_cir) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");

	vector<int> ans(m);

	int flow;
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < n - 1; ++j) {
			flow = f[i][j] + sum_cap[i][j];
			for (vector<edge>::iterator it = data[i][j].begin(); it != data[i][j].end(); ++it) {
				if (flow > 0) {
					int t = min(flow, it->cap);
					ans[it->id] = t;
					flow -= t;
				}
			}
		}
	}

	for (int i = 0; i < ans.size(); ++i) {
		printf("%d\n", ans[i]);
	}

	return 0;
}