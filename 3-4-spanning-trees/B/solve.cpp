#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "spantree2"

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
	edge(int from, int to, int w) : from(from), to(to), w(w) {}

	bool operator < (edge const& e) const {
		return w < e.w;
	}
};

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
	int from, to, w;

	vector<edge> edges;

	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &from, &to, &w);
		from--; to--;
		edges.push_back(edge(from, to, w));
	}

	sort(edges.begin(), edges.end());

	DSU dsu(n);

	long long int ans = 0;

	for (int i = 0; i < m; ++i) {
		from = edges[i].from;
		to = edges[i].to;
		w = edges[i].w;
	
		if (dsu.find(from) != dsu.find(to)) {
			dsu.unite(from, to);
			ans += w;
		}
	}

	cout << ans;

	return 0;
}