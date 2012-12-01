#pragma comment(linker, "/STACK:32000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "paths"

vector< vector<int> > g;
vector<bool> used;
vector<int> mt;

bool kuhn(int v) {
	if (used[v]) {
		return false;
	}
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || kuhn(mt[to])) {
			mt[to] = v;
			return true;
		}
	}

	return false;
}

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, k;
	cin >> n >> m;

	g.resize(n);

	int from, to;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &from, &to);
		--from;
		--to;
		g[from].push_back(to);
	}

	mt.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		used.assign(n, false);
		kuhn(i);
	}
	int ans = 0;
	for (int i = 0; i < mt.size(); ++i) {
		if (mt[i] != -1) {
			++ans;
		}
	}
	cout << n - ans;

	return 0;
}