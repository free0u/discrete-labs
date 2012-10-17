#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repa(i, a, b) for (int i = (a); i <= (b); ++i)
#define sqr(x) ((x)*(x))
#define all(c) c.begin(), c.end()
#define re return

#define task_name "radixsort"

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, k;
	cin >> n >> m >> k;

	vector<string> data(n);
	vector<string> temp(n);
	for (int i = 0; i < n; ++i) {
		cin >> data[i];
	}

	for (int step = 0; step < m; ++step) {
		if (step == k) {
			for (int i = 0; i < data.size(); ++i) {
				cout << data[i] << endl;
			}
			return 0;
		}

		int ind_sort = m - step - 1;
		vector<vector<int> > cnt(256);
		for (int i = 0; i < n; ++i) {
			cnt[data[i][ind_sort]].push_back(i);
		}

		int pos = 0;
		for (int i = 0; i < 256; ++i) {
			for (int j = 0; j < cnt[i].size(); ++j) {
				temp[pos++] = data[cnt[i][j]];
			}
		}

		data.assign(temp.begin(), temp.end());
	}

	// если нужен самый последний шаг
	for (int i = 0; i < data.size(); ++i) {
		cout << data[i] << endl;
	}



	return 0;
}