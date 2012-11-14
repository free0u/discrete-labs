#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "chinese"

struct edge {
	int from, to, w;
	
	edge() {}
	
	edge(int from, int to, int w) : from(from), to(to), w(w)
	{
	}
};

typedef vector< edge > Edges;
typedef vector< Edges > Graph;


const int inf = 1e9 + 31;

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
			
			if (to == start_v) continue;
			m[to] = min(m[to], w);
		}
	}

	// decrease edges
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			from = g[i][j].from;
			to = g[i][j].to;

			if (to == start_v) continue;
			g[i][j].w -= m[to];
		}
	}
}

bool find_mst(Graph &g, Edges &edges, vector<int> &edges_in_mst) {
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
	Graph source_graph(n);
	int from, to, w;
	edge e;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &from, &to, &w);
		from--; to--;
		e = edge(from, to, w);
		source_edges.push_back(e);
		source_graph[from].push_back(e);
	}

	vector<int> ind;
	bool ok = find_mst(source_graph, source_edges, ind);
	if (ok) {
		long long res = 0;
		for (int i = 0; i < ind.size(); ++i) {
			res += source_edges[ind[i]].w;
		}
		cout << "YES" << endl;
		cout << res;
	} else
	{
		cout << "NO";
	}

	return 0;
}