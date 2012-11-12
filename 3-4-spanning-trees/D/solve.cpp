#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
#define task_name "euler"

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, x;
	cin >> n;

	vector< vector<int> > g(n, vector<int> (n));

	int cnt_odd = 0;
	int v1 = -1, v2 = -1;

	for (int i = 0; i < n; ++i) {
		scanf("%d", &m);
		if (m & 1) {
			++cnt_odd;
			if (v1 == -1) {
				v1 = i;
			} else if (v2 == -1) {
				v2 = i;
			}
		}
		for (int j = 0; j < m; ++j) {
			scanf("%d", &x);
			x--;
			g[i][x]++;
		}
	}


	if (cnt_odd != 0 && cnt_odd != 2) {
		cout << -1;
		return 0;
	}

	// have cycle or path
	bool have_path = (cnt_odd == 2);
	if (have_path) {
		g[v1][v2]++;
		g[v2][v1]++;
	}

	// have cycle

	stack<int> st;
	st.push(0);
	
	vector<int> ans;

	while (!st.empty()) {
		int v = st.top();

		bool degree_is_null = true;
		for (int i = 0; i < n; ++i) {
			if (g[v][i]) {
				degree_is_null = false;
				break;
			}
		}

		if (degree_is_null) {
			ans.push_back(v);
			st.pop();
		} else
		{
			for (int i = 0; i < n; ++i) {
				if (g[v][i]) {
					--g[v][i];
					--g[i][v];
					st.push(i);
					break;
				}
			}
		}
	}

	if (!have_path) { // have cycle
		cout << ans.size() - 1 << endl;
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d ", ans[i] + 1);
		}
		return 0;
	}

	if (have_path) {
		vector<int> ans2;

		for (int i = 0; i < ans.size() - 1; ++i) {
			if ((ans[i] == v1 && ans[i + 1] == v2) || (ans[i] == v2 && ans[i + 1] == v1)) {
				for (int j = i + 1; j < ans.size(); ++j) {
					ans2.push_back(ans[j]);
				}
				for (int j = 1; j <= i; ++j) {
					ans.push_back(ans[j]);
				}
				ans = ans2;
				break;
			}
		}
	}

	cout << ans.size() - 1 << endl;
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d ", ans[i] + 1);
	}

	return 0;
}