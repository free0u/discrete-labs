#pragma comment(linker, "/STACK:64000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "chinese"


class DSU {
public:
	DSU() {}
	DSU(int n) {
		par.resize(n);
		for (int i = 0; i < n; ++i) {
			par[i] = i;
		}
	}
	int find(int v) {
		if (v == par[v]) return v;
		return par[v] = find(par[v]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x != y) {
			if (rand() & 1) {
				par[x] = y;
			} else
			{
				par[y] = x;
			}
		}
	}
private:
	vector<int> par;
};

struct edge {
	int from, to, w;
	
	edge() {}
	
	edge(int from, int to, int w) : from(from), to(to), w(w)
	{
	}
};

typedef vector< edge > Edges;
typedef vector< Edges > Graph;
typedef pair<int, int> pii;

const int inf = 1e9 + 31;

// for test connectivity
void dfs(Graph &g, vector<bool> &used, int v) {
	used[v] = true;
	int from, to, w;
	for (int i = 0; i < g[v].size(); ++i) {
		from = g[v][i].from;
		to = g[v][i].to;
		w = g[v][i].w;
		if (!used[to]) {
			dfs(g, used, to);
		}
	}
}

void dfs_zero_edges(Graph &g, vector<bool> &used, int v, vector<int> &order, vector<pii> &ind) {
	used[v] = true;
	int from, to, w;
	for (int i = 0; i < g[v].size(); ++i) {
		from = g[v][i].from;
		to = g[v][i].to;
		w = g[v][i].w;
		if (!used[to] && w == 0) {
			ind.push_back(make_pair(v, i));
			dfs_zero_edges(g, used, to, order, ind);
		}
	}
	order.push_back(v);
}


void edges_to_zero(Graph &g, int start_v) {
	int n = g.size();
	vector<int> m(n, inf);
	int from, to, w;

	// find minimum
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			from = g[i][j].from;
			to = g[i][j].to;
			w = g[i][j].w;
			
			//if (to == start_v) continue;
			m[to] = min(m[to], w);
		}
	}

	// decrease edges
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			from = g[i][j].from;
			to = g[i][j].to;

			//if (to == start_v) continue;
			g[i][j].w -= m[to];
		}
	}
}

bool find_mst(Graph &g, int start_v, vector<pii> &indexes) {
	int n = g.size();
	vector<bool> used(n);
	dfs(g, used, start_v);

	bool ok = true;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			ok = false;
			break;
		}
	}

	// not connectivity graph
	if (!ok) {
		return false;
	}

	// we have connectivity graph
	// test for tree with zero edges:
	edges_to_zero(g, start_v);
	used.assign(n, false);
	vector<int> order;
	dfs_zero_edges(g, used, start_v, order, indexes);

	ok = true;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			ok = false;
			break;
		}
	}
	// find tree with zero edges
	if (ok) {
		return true;
	}

	// not find tree with zero edges =(
	// build zero components graph:
	
	DSU dsu(n);
	// order was calculate by dfs_zero_edges


	// find_mst(zero_component_graph, comp_with_start_v, indexes_in_zero_component_graph);

	

	return false;
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
	Edges source_edges;
	Graph source_graph(n), g_to_mst(n);
	int from, to, w;
	edge e;
	// TODO delete
	vector< vector<int> > test_g(n, vector<int> (n, -1));
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &from, &to, &w);
		from--; to--;
		e = edge(from, to, w);
		source_edges.push_back(e);
		source_graph[from].push_back(e);
		g_to_mst[from].push_back(e);
		test_g[from][to] = w;
	}

	vector<pii> ind;
	bool ok = find_mst(g_to_mst, 0, ind);
	if (ok) {
		long long res = 0;
		for (int i = 0; i < ind.size(); ++i) {
			int x = ind[i].first;
			int y = ind[i].second;
			res += source_graph[x][y].w;
		}
		cout << "YES" << endl;
		cout << res;
	} else
	{
		cout << "NO";
	}

	cout << endl << endl;
	for (int i = 0; i < n; ++i ){
		for (int j = 0; j < n; ++j) {
			cout << test_g[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}