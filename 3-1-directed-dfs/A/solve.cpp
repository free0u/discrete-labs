#pragma comment(linker, "/STACK:32000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "topsort"

vector< vector<int> > g;
vector<int> color, topsort;
// 0 white
// 1 gray
// 2 black

bool cycle;

void dfs(int v) {
	color[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (color[to] == 0) {
			dfs(to);
		} else if (color[to] == 1) { // проблема, нашли цикл
			cycle = true;
		}
	}

	color[v] = 2;
	topsort.push_back(v);
}


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
	g.resize(n);
	color.resize(n);
	int x, y;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		g[x - 1].push_back(y - 1);
	}

	cycle = false;
	for (int i = 0; i < n; ++i) {
		if (color[i] == 0) {
			dfs(i);
		}
	}
	if (cycle) {
		printf("-1\n");
	} else {
		for (int i = topsort.size() - 1; i >= 0; --i) {
			printf("%d ", topsort[i] + 1);
		}
	}
	return 0;
}