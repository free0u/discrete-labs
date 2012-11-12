#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "mindiff"

class DSU {
public:
	DSU() {}
	DSU(int n) {
		par.resize(n);
		init();
	}

	void init() {
		for (int i = 0; i < par.size(); ++i) {
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
	
	const long long inf = 1e16;

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

	if (n == 1) {
		printf("NO\n");
		return 0;
	}


	DSU dsu(n);
	vector<bool> in_mst;
	long long min_cost, max_cost, ans;
	ans = inf;

	for (int start = 0; start < m; ++start) {
		dsu.init();
		in_mst.assign(n, false);
		min_cost = inf;
		max_cost = -inf;

		for (int i = start; i < m; ++i) {
			from = edges[i].from;
			to = edges[i].to;
			w = edges[i].w;

			if (dsu.find(from) != dsu.find(to)) {
				dsu.unite(from, to);
				if (w > max_cost) {
					max_cost = w;
				}
				if (w < min_cost) {
					min_cost = w;
				}
				in_mst[from] = true;
				in_mst[to] = true;
			}
		}

		bool is_mst = true;
		for (int i = 0; i < n; ++i) {
			if (!in_mst[i]) {
				is_mst = false;
				break;
			}
		}

		if (is_mst && min_cost != inf && max_cost != -inf) {
			long long d = abs(min_cost - max_cost);
			if (d < ans) {
				ans = d;
			}
		}
	}
	printf("YES\n%d", ans);

	return 0;
}