#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define task_name "pathbge1"

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	vector< vector<int> > g;
	int n, m, x, y;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	queue<int> q;
	q.push(0);
	vector<bool> used(n);
	vector<int> d(n);
	used[0] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < g[v].size(); ++i) {
			int to = g[v][i];
			if (!used[to]) {
				used[to] = true;
				q.push(to);
				d[to] = d[v] + 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", d[i]);
	}
	return 0;
}