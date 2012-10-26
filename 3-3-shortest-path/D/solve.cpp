#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
#define task_name "pathbgep"

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	const int inf = 1e9 + 31;

	int n, m;
	cin >> n >> m;
	vector< vector< pair<int, int> > > g(n);
	int x, y, z;
	pair<int, int> pii;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &x, &y, &z);
		--x; --y;
		pii.second = z;
		pii.first = y;
		g[x].push_back(pii);
		pii.first = x;
		g[y].push_back(pii);
	}

	vector<int> d(n, inf);
	d[0] = 0;
	set< pair<int, int> > used;
	used.insert(make_pair(0, 0));
	while (!used.empty()) {
		int v = used.begin()->second;
		used.erase(used.begin());

		for (int i = 0; i < g[v].size(); ++i) {
			int to = g[v][i].first;
			int w = g[v][i].second;

			if (d[to] > d[v] + w) {
				used.erase(make_pair(d[to], to));
				d[to] = d[v] + w;
				used.insert(make_pair(d[to], to));
			}
		}
	}


	
	for (int i = 0; i < n; ++i) {
		printf("%d ", d[i]);
	}

	return 0;
}