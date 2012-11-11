#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "spantree"
#define sqr(x) ((x)*(x))

const double inf = 1e8;

struct point {
	double x, y;
	point() : x(0), y(0) {}
	point(double _x, double _y) : x(_x), y(_y) {}

	double dist(point &p) {
		return sqrt(sqr(x - p.x) + sqr(y - p.y));
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
	
	vector<point> g;

	int n;
	cin >> n;
	double x, y;
	for (int i = 0; i < n; ++i) {
		scanf("%lf %lf\n", &x, &y);
		g.push_back(point(x, y));
	}

	vector<bool> in_mst(n);
	vector<double> min_edge(n, inf);

	double ans = 0;

	min_edge[0] = 0;
	for (int i = 0; i < n; ++i) {
		int v = -1;
		for (int j = 0; j < n; ++j) {
			if (in_mst[j]) continue;
			if (v == -1 || min_edge[j] < min_edge[v]) {
				v = j;
			}
		}
		in_mst[v] = true;
		ans += min_edge[v];

		for (int j = 0; j < n; ++j) {
			double dist = g[j].dist(g[v]); // dist(j, v)
			if (dist < min_edge[j]) {
				min_edge[j] = dist;
			}
		}
	}

	printf("%.6f", ans);

	return 0;
}