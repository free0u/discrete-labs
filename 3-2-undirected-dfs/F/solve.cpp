#pragma comment(linker, "/STACK:31000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
#define task_name "biconv"

// pair: first - vertex, second - id
vector< vector< pair<int, int> > > g;

vector<bool> used;
vector<int> time_in, time_up, colors;
int timer, max_color;

void dfs(int v, int p = -1) {
	used[v] = true;
	time_in[v] = time_up[v] = timer;
	timer++;
	int child = 0;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i].first;
		if (to == p) continue;
		if (used[to]) {
			time_up[v] = min(time_up[v], time_in[to]);
		} else
		{
			dfs(to, v);
			time_up[v] = min(time_up[v], time_up[to]);
			++child;
		}
	}
}

void paint(int v, int color = -1, int parent = -1) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i].first;
		int id = g[v][i].second;
		
		if (to == parent) continue;
		
		if (!used[to]) {
			if (time_up[to] >= time_in[v]) {
				++max_color;
				colors[id] = max_color;
				paint(to, max_color, v);
			} else
			{
				colors[id] = color;
				paint(to, color, v);
			}
		} else
		{
			if (time_in[to] <= time_in[v]) {
				colors[id] = color;
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
		g[x].push_back(make_pair(y, i));
		g[y].push_back(make_pair(x, i));
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

	colors.resize(m);
	used.assign(n, false);
	max_color = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			paint(i);
		}
	}

	cout << max_color << endl;
	for (int i = 0; i < m; ++i) {
		printf("%d ", colors[i]);
	}

	return 0;
}