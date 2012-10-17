#pragma comment(linker, "/STACK:31000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "bipartite"

vector< vector<int> > g;
vector<bool> used, part;

bool bipartite = true;

void dfs(int v, bool p = false) {
	part[v] = p;
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (used[to]) {
			if (part[v] == part[to]) {
				bipartite = false;
			}
		} else
		{
			dfs(to, !p);
		}
	}
}

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, x, y;
	cin >> n >> m;
	g.resize(n);

	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	used.resize(n);
	part.resize(n);
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}
	printf("%s", bipartite ? "YES" : "NO");
	return 0;
}