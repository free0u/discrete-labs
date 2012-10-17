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
#define task_name "shortpath"

vector< vector< pair<int, int> > > g;

const int inf = 1e9 + 31;


vector<bool> used;
vector<int> topsort;

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i].first;
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
	
	int n, m, t, s;
	cin >> n >> m >> s >> t;
	--s; --t;
	int x, y, z;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &x, &y, &z);
		g[x - 1].push_back(make_pair(y - 1, z));
	}

	used.resize(n);
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}
	vector<int> dist(n, inf);
	dist[s] = 0;
	reverse(topsort.begin(), topsort.end());
	for (int i = 0; i < topsort.size(); ++i) {
		int from = topsort[i];
		for (int j = 0; j < g[from].size(); ++j) {
			int to = g[from][j].first;
			int w = g[from][j].second;
			//if (dist[from] == inf) continue;
			if (dist[to] > dist[from] + w) {
				dist[to] = dist[from] + w;
			}
		}
	}

	
	//set< pair<int, int> > used;
	//used.insert(make_pair(0, s));
	//while (!used.empty()) {
	//	int v = used.begin()->second;
	//	used.erase(used.begin());

	//	for (int i = 0; i < g[v].size(); ++i) {
	//		int to = g[v][i].first;
	//		int w = g[v][i].second;

	//		if (dist[to] > dist[v] + w) {
	//			used.erase(make_pair(dist[to], to));
	//			dist[to] = dist[v] + w;
	//			used.insert(make_pair(dist[to], to));
	//		}
	//	}
	//}


	if (dist[t] == inf) {
		printf("Unreachable\n");
	} else {
		cout << dist[t] << endl;
	}

	return 0;
}