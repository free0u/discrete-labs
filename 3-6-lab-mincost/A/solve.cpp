#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "assignment"

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	const int inf = 1e9 + 31;

	int n, x;
	cin >> n;
	vector< vector<int> > a(n + 1, vector<int> (n + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &x);
			a[i][j] = x;
		}
	}

	vector<int> u(n + 1), v(n + 1), p(n + 1), way(n + 1);
	for (int i = 1; i <= n; ++i) {
		p[0] = i;
		int j0 = 0;
		vector<int> minv(n + 1, inf);
		vector<char> used(n + 1, false);
		do {
			used[j0] = true;
			int i0 = p[j0];
			int delta = inf,  j1;
			for (int j = 1; j <= n; ++j) {
				if (!used[j]) {
					int cur = a[i0][j]-u[i0]-v[j];
					if (cur < minv[j])
						minv[j] = cur,  way[j] = j0;
					if (minv[j] < delta) {
						delta = minv[j];
						j1 = j;
					}
				}
			}
			for (int j=0; j <= n; ++j) {
				if (used[j]) {
					u[p[j]] += delta,v[j] -= delta;
				}
				else
				{
					minv[j] -= delta;
				}
			}
			j0 = j1;
		} while (p[j0] != 0);

		do {
			int j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
		} while (j0);
	}
	cout << -v[0] << endl;
	for (int i = 1; i <= n; ++i) {
		printf("%d %d\n", p[i], i);
	}

	//vector<int> ans(n + 1);
	//for (int i = 1; i <= n; ++i) {
	//	ans[p[i]] = i;
	//}

	return 0;
}