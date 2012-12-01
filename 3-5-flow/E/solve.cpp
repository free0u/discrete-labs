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

struct edge {
	int to, id, c, f;
	int x, y;
	edge() {}
	edge(int to, int id, int c, int f) : to(to), id(id), c(c), f(f)
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
	vector< vector<edge> > g(n);

	int from, to, w;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &from, &to, &w);
		--from;
		--to;
		g[from].push_back(edge(to, i, w, 0));
		g[to].push_back(edge(from, i, 0, 0));

		g[from].back().x = to;
		g[from].back().y = g[to].size() - 1;

		g[to].back().x = from;
		g[to].back().y = g[from].size() - 1;
	}

	while (true) {
		// find path
		vector<int> from(n, -1);
		vector<int> from_id(n, -1);
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int i = 0; i < g[v].size(); ++i) {
				int to = g[v][i].to;
				if (from[to] == -1 && (g[v][i].c - g[v][i].f) > 0) {
					q.push(to);
					from[to] = v;
					from_id[to] = g[v][i].id;
				}
			}
		}

		if (from[n - 1] == -1) { // not found path
			break;
		}

		long long cf = inf;
		edge e;
		for (int cur = n - 1; cur != 0; ) {
			int prev = from[cur];
			
			for (int i = 0; i < g[prev].size(); ++i) {
				e = g[prev][i];
				if (e.to == cur && e.id == from_id[cur]) {
					cf = min(cf, (long long)(g[prev][i].c - g[prev][i].f));
					break;
				}
			}
			cur = prev;
		}

		for (int cur = n - 1; cur != 0; ) {
			int prev = from[cur];
			for (int i = 0; i < g[prev].size(); ++i) {
				e = g[prev][i];
				if (e.to == cur && e.id == from_id[cur]) {
					g[prev][i].f += cf;
					int x = g[prev][i].x;
					int y = g[prev][i].y;
					g[x][y].f -= cf;
					break;
				}
			}
			cur = prev;
		}
	}
	
	/*long long ans = 0;
	for (int i = 0; i < g[0].size(); ++i) {
		ans += g[0][i].f;
	}
	cout << ans;*/


	vector<int> flow;
	vector< vector<int> > edges;

	while (true) {
		vector<int> par(n, -1);
		vector<int> par_id(n, -1);
		vector<bool> used(n, false);
		int cur = 0, next;
		long long cf = inf;
		while (true) {
			used[cur] = true;
			next = -1;
			for (int i = 0; i < g[cur].size(); ++i) {
				if (g[cur][i].f > 0) {
					next = g[cur][i].to;
					cf = min(cf, (long long)g[cur][i].f);
					par[next] = cur;
					par_id[next] = g[cur][i].id;
					cur = next;
					break;
				}
			}
			if (cur == -1) {
				break;
			}

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
		edge e;
		for (; cur != 0; cur = par[cur]) {
			int prev = par[cur];
			
			for (int i = 0; i < g[prev].size(); ++i) {
				e = g[prev][i];
				if (e.to == cur && e.id == par_id[cur]) {
					g[prev][i].f -= cf;
					int x = g[prev][i].x;
					int y = g[prev][i].y;
					g[x][y].f += cf;
					edges.back().push_back(g[prev][i].id);
					break;
				}
			}
		}
	}

	cout << flow.size() << endl;
	for (int i = 0; i < flow.size(); ++i) {
		printf("%d ", flow[i]);
		printf("%d ", edges[i].size());
		for (int j = edges[i].size() - 1; j >= 0; --j) {
			printf("%d ", edges[i][j] + 1);
		}
		printf("\n");
	}

	return 0;
}