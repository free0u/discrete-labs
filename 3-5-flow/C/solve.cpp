#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define task_name "cut"

const int inf = 1e9 + 31;

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

	vector< vector<int> > c(n, vector<int> (n));
	int from, to, w;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &from, &to, &w);
		--from;
		--to;
		c[from][to] = w;
		c[to][from] = w;
	}

	vector< vector<int> > f(n, vector<int> (n));
	while (true) {

		// find path
		vector<int> from(n, -1);
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int i = 0; i < n; ++i) {
				if (from[i] == -1 && (c[v][i] - f[v][i]) > 0) {
					q.push(i);
					from[i] = v;
				}
			}
		}

		if (from[n - 1] == -1) { // not found path
			break;
		}

		int cf = inf;
		for (int cur = n - 1; cur != 0; ) {
			int prev = from[cur];
			cf = min(cf, c[prev][cur] - f[prev][cur]);
			cur = prev;
		}

		for (int cur = n - 1; cur != 0; ) {
			int prev = from[cur];
			f[prev][cur] += cf;
			f[cur][prev] = -f[prev][cur];
			cur = prev;
		}
	}

	// find cut
	vector<int> used(n);
	queue<int> q;
	q.push(0);
	used[0] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < n; ++i) {
			if (!used[i] && (c[v][i] - f[v][i]) > 0) {
				q.push(i);
				used[i] = true;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			++cnt;
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			printf("%d ", i + 1);
		}
	}

	return 0;
}