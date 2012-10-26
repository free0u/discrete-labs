#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
#define task_name "negcycle"

inline long long max(long long a, long long b) {
	return a > b ? a : b;
}


int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	const int inf = 1e9;

	int n;
	cin >> n;
	vector< vector<int> > g(n, vector<int> (n));
	int x, y, z;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &g[i][j]);
		}
	}

	vector<int> d(n, inf);
	vector<int> p(n, -1);
	d[0] = 0;
	for (int i = 0; i < n; ++i) {
		x = -1;
		for (int from = 0; from < n; ++from) {
			for (int to = 0; to < n; ++to) {
				int w = g[from][to];
				if (w == inf) continue;
				if (d[to] > d[from] + w) {
					d[to] = max(-inf, d[from] + w);
					p[to] = from;
					x = to;
				}
			}
		}
	}
	if (x == -1) {
		printf("NO\n");
		return 0;
	}
	
	y = x;
	for (int i = 0; i < n; ++i) {
		y = p[y];
	}
	vector<int> path;
	for (int cur = y; ; cur = p[cur]) {
		path.push_back(cur);
		if (cur == y && path.size() > 1) break;
	}
	reverse(path.begin(), path.end());
	cout << "YES" << endl;
	cout << path.size() << endl;
	for (int i = 0; i < path.size(); ++i) {
		printf("%d ", path[i] + 1);
	}

	return 0;
}