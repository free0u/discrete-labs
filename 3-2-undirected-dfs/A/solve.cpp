#pragma comment(linker, "/STACK:31000000")
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "components"

vector< vector<int> > g;
vector<bool> used;
vector<int> ans;
int num;

void dfs(int v) {
	used[v] = true;
	ans[v] = num;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to]) {
			dfs(to);
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
	
	int n, m;
	cin >> n >> m;

	g.resize(n);

	int x, y;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	used.assign(n, false);
	ans.assign(n, 0);
	num = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			++num;
			dfs(i);
		}
	}

	cout << num << endl;
	for (int i = 0; i < n; ++i) {
		printf("%d ", ans[i]);
	}
	return 0;
}