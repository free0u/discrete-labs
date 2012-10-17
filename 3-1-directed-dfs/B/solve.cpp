#pragma comment(linker, "/STACK:32000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "cond"

vector< vector<int> > g, g_t;
vector<bool> used;
vector<int> topsort;
vector<int> ans;
int num_comp;

void dfs1(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to]) {
			dfs1(to);
		}
	}
	topsort.push_back(v);
}

void dfs2(int v) {
	used[v] = true;
	ans[v] = num_comp;
	for (int i = 0; i < g_t[v].size(); ++i) {
		int to = g_t[v][i];
		if (!used[to]) {
			dfs2(to);
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
	g_t.resize(n);
	ans.resize(n);
	int x, y;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d\n", &x, &y);
		g[x - 1].push_back(y - 1);
		g_t[y - 1].push_back(x - 1);
	}
	
	used.assign(n, false);
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs1(i);
		}
	}
	
	used.assign(n, false);
	for (int i = 0; i < n; ++i) {
		int v = topsort[n - i - 1];
		if (!used[v]) {
			++num_comp;
			dfs2(v);
		}
	}
	cout << num_comp << endl;
	for (int i = 0; i < n; ++i) {
		printf("%d ", ans[i]);
	}

	return 0;
}