#pragma comment(linker, "/STACK:32000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "cycle"

vector< vector<int> > g;
vector<int> color; // 0 white; 1 gray; 2 black;
vector<int> par;
int cycle_begin, cycle_end;

void dfs(int v) {
	color[v] = 1;

	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (color[to] == 0) {
			par[to] = v;
			dfs(to);
		} else if (color[to] == 1) { // find a cycle
			cycle_begin = to;
			cycle_end = v;

			vector<int> ans;
			for (int j = cycle_end; j != cycle_begin; j = par[j]) {
				ans.push_back(j);
			}
			ans.push_back(cycle_begin);
			printf("YES\n");
			for (int j = ans.size() - 1; j >= 0; --j) {
				printf("%d ", ans[j] + 1);
			}
			exit(0);
		}
	}

	color[v] = 2;
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
	int x, y;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		g[x - 1].push_back(y - 1);
	}

	color.assign(n, 0);
	par.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		if (color[i] == 0) {
			dfs(i);
		}
	}
	printf("NO\n");
	return 0;
}