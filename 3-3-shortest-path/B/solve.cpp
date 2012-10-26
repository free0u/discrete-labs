#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "pathmgep"

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	const int inf = 1e9 + 31;

	int n, s, f;
	cin >> n >> s >> f;
	--s; --f;
	vector< vector<int> > g(n, vector<int> (n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &g[i][j]);
		}
	}

	vector<int> d(n, inf);
	d[s] = 0;
	vector<bool> used(n);
	for (int i = 0; i < n; ++i) {
		int v = -1;
		for (int j = 0; j < n; ++j) {
			if (!used[j] && (v == -1 || d[j] < d[v])) {
				v = j;
			}
		}
		if (d[v] == inf) break;
		used[v] = true;
		for (int to = 0; to < n; ++to) {
			int w = g[v][to];
			if (w == -1) continue;
			if (d[v] + w < d[to]) {
				d[to] = d[v] + w;
			}
		}
	}
	printf("%d", d[f] == inf ? -1 : d[f]);

	return 0;
}