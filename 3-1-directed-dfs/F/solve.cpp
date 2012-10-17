#pragma comment(linker, "/STACK:32000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>


using namespace std;
#define task_name "hamiltonian"

vector< vector<int> > g;
vector<bool> used;
vector<int> topsort;

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to]) {
			dfs(to);
		}
	}
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
	int x, y;
	g.resize(n);
	used.resize(n);
	
	set< pair<int, int> > edges;
	
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		--x;--y;
		g[x].push_back(y);
		edges.insert(make_pair(x, y));
	}
	
	

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}
	reverse(topsort.begin(), topsort.end());

	int cnt = 0;
	for (int i = 0; i < topsort.size() - 1; ++i) {
		int from = topsort[i];
		int to = topsort[i + 1];
		if (edges.find(make_pair(from, to)) == edges.end()) {
			cnt++;
		}
	}
	int from = topsort[topsort.size() - 1];
	int to = topsort[0];
	if (edges.find(make_pair(from, to)) == edges.end()) {
		cnt++;
	}

	printf("%s\n", cnt > 1 ? "NO" : "YES");
	return 0;
}