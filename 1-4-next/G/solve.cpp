#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repa(i, a, b) for (int i = (a); i <= (b); ++i)
#define sqr(x) ((x)*(x))
#define all(c) c.begin(), c.end()
#define re return

#define task_name "nextpartition"

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	vi a;
	int x, W;
	cin >> W;

	string s;
	getline(cin, s);
	stringstream in(s);
	char c;
	in >> c;
	while (in >> x) {
		in >> c;
		a.push_back(x);
	}

	int sum_pref = W;
	int sum_suff;

	for (int i = a.size() - 1; i >= 0; --i) {
		sum_pref -= a[i];
		sum_suff = W - sum_pref;
		for (int j = a[i] + 1; j <= sum_suff; ++j) {
			int t = sum_suff - j;
			if (t == 0) {
				cout << W << "=";
				rep(g, i) cout << a[g] << "+";
				cout << j;
				re 0;
			}
			int cnt_j = t / j;
			if (cnt_j > 0) {
				cout << W << "=";
				rep(g, i) cout << a[g] << "+";
				cout << j << "+";
				rep(g, cnt_j - 1) cout << j << "+";
				cout << j + t % j;
				re 0;
			}
		}
	}

	cout << "No solution";

	return 0;
}