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
#define task_name "decomposition"

const long long inf = 1e16 + 31;

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

	map< pair<int, int>, int> save_edges;
	
	vector< vector<int> > c(n, vector<int> (n));
	int from, to, w;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &from, &to, &w);
		--from;
		--to;
		c[from][to] = w;
		save_edges[make_pair(from, to)] = i + 1;
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

		long long cf = inf;
		for (int cur = n - 1; cur != 0; ) {
			int prev = from[cur];
			cf = min(cf, (long long)(c[prev][cur] - f[prev][cur]));
			cur = prev;
		}

		for (int cur = n - 1; cur != 0; ) {
			int prev = from[cur];
			f[prev][cur] += cf;
			f[cur][prev] = -f[prev][cur];
			cur = prev;
		}
	}
	
	vector<int> flow;
	vector< vector<int> > edges;

	while (true) {
		vector<int> par(n, -1);
		vector<bool> used(n, false);
		int cur = 0, next;
		long long cf = inf;
		while (true) {
			used[cur] = true;
			next = -1;
			for (int i = 0; i < n; ++i) {
				if (f[cur][i] > 0) {
					next = i;
					cf = min(cf, (long long)f[cur][i]);
					break;
				}
			}
			if (next == -1) {
				break;
			}

			par[next] = cur;
			cur = next;

			if (cur == n - 1 || used[cur]) {
				break;
			}
		}
		if (next == -1) {
			break;
		}

		flow.push_back(cf);
		edges.push_back(vector<int> ());

		// find min edge
		for (; cur != 0; cur = par[cur]) {
			int prev = par[cur];
			f[prev][cur] -= cf;
			f[cur][prev] = -f[prev][cur];

			edges.back().push_back(save_edges[make_pair(prev, cur)]);
		}
	}

	cout << flow.size() << endl;
	for (int i = 0; i < flow.size(); ++i) {
		printf("%d ", flow[i]);
		printf("%d ", edges[i].size());
		for (int j = edges[i].size() - 1; j >= 0; --j) {
			printf("%d ", edges[i][j]);
		}
		printf("\n");
	}

	return 0;
}