#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "pathsg"

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	const int inf = 1e9 + 31;

	int n, m;
	cin >> n >> m;
	vector< vector<int> > g(n, vector<int> (n, inf));
	int x, y, z;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &x, &y, &z);
		g[x - 1][y - 1] = z;
	}
	for (int i = 0; i < n; ++i) {
		g[i][i] = 0;
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}

	return 0;
}