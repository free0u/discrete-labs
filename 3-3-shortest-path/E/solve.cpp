#pragma comment(linker, "/STACK:31000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
#define task_name "path"

inline long long max(long long a, long long b) {
	return a > b ? a : b;
}


vector< vector<int> > g;
vector<bool> used;

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to]) {
			dfs(to);
		}
	}
}

struct edge {
	int from, to;
	long long w;
	edge() {}
	edge(int a, int b, long long c) {
		from = a;
		to = b;
		w = c;
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
	
	const long long inf = 7e18;

	int n, m, s;
	cin >> n >> m >> s;
	--s;

	vector<edge> edges;
	g.resize(n);
	int x, y;
	long long z;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %I64d", &x, &y, &z);
		--x; --y;
		g[x].push_back(y);
		edges.push_back(edge(x, y, z));
	}

	vector<long long> d(n, inf);
	d[s] = 0;
	
	edge e;
	for (int i = 0; i < n - 1; ++i) {
		bool any_changed = false;
		for (int j = 0; j < m; ++j) {
			e = edges[j];
			if (d[e.from] < inf) {
				if (d[e.to] > d[e.from] + e.w) {
					d[e.to] = max(-inf, d[e.from] + e.w);
					any_changed = true;
				}
			}
		}
		if (!any_changed) break;
	}

	vector<long long> d2(d);
	for (int j = 0; j < m; ++j) {
		e = edges[j];
		if (d2[e.from] < inf) {
			if (d2[e.to] > d2[e.from] + e.w) {
				d2[e.to] = max(-inf, d2[e.from] + e.w);
			}
		}
	}
	
	used.resize(n);
	for (int i = 0; i < n; ++i) {
		if (d[i] != d2[i]) {
			dfs(i);
		}
	}

	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			printf("-\n");
		} else 
		{
			if (d[i] < inf) {
				printf("%I64d\n", d[i]);
			} else
			{
				printf("*\n");
			}
		}
	}
	

	return 0;
}