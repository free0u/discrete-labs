#pragma comment(linker, "/STACK:31000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "bicone"

vector< vector<int> > g;

vector<bool> used;
vector<int> time_in, time_up, colors;
int timer, max_color;

void dfs(int v, int p = -1) {
	used[v] = true;
	time_in[v] = time_up[v] = timer;
	timer++;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p) continue;
		if (used[to]) {
			time_up[v] = min(time_up[v], time_in[to]);
		} else
		{
			dfs(to, v);
			time_up[v] = min(time_up[v], time_up[to]);
			if (time_up[to] > time_in[v]) {
				int x = v;
				int y = to;
				if (x > y) swap(x, y);
			}
		}
	}
}

void paint(int v, int color) {
	colors[v] = color;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (colors[to] == 0) {
			if (time_up[to] == time_in[to]) {
				max_color++;
				paint(to, max_color);
			} else
			{
				paint(to, color);
			}
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

	pair<int, int> bridge_pair;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &x, &y);
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
		if (x > y) swap(x, y);
		bridge_pair.first = x;
		bridge_pair.second = y;
	}

	timer = 0;
	used.resize(n);
	time_in.resize(n);
	time_up.resize(n);
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}

	colors.resize(n);
	max_color = 0;
	for (int i = 0; i < n; ++i) {
		if (colors[i] == 0) {
			max_color++;
			paint(i, max_color);
		}
	}

	cout << max_color << endl;
	for (int i = 0; i < n; ++i) {
		printf("%d ", colors[i]);
	}

	return 0;
}