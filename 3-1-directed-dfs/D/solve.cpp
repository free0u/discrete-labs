#pragma comment(linker, "/STACK:32000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "game"

vector< vector<int> > g, g_t;
vector<bool> used;

vector<int> type; // 0 - ничейная. 1 - win, 2 - loose
vector<int> degree;
void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g_t[v].size(); ++i) {
		int to = g_t[v][i];
		if (!used[to]) {
			if (type[v] == 2) { // v - loose
				type[to] = 1; // to - win
			} else if (++degree[to] == g[to].size()) {
				type[to] = 2; //loose
			} else
				continue;
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
	
	int n, m, s;
	cin >> n >> m >> s;
	--s;
	int x, y;
	g.resize(n);
	g_t.resize(n);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		g[x - 1].push_back(y - 1);
		g_t[y - 1].push_back(x - 1);
	}

	used.assign(n, false);
	type.assign(n, false);
	degree.resize(n);
	for (int i = 0; i < n; ++i) {
		if (g[i].size() == 0) {
			type[i] = 2;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (type[i] != 0 && !used[i]) {
			dfs(i);
		}
	}

	cout << (type[s] == 1 ? "First player wins" : "Second player wins");
	return 0;
}