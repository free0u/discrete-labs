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

#define task_name "part2num"


vector<vector<ll> > pre;

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<ll> a;
	string st;
	getline(cin, st);
	stringstream in(st);
	ll n = 0;
	int x;
	while (in >> x) {
		n += x;
		a.push_back(x);
	}


	ll ans = 0;
	ll last = 1, cur_sum = 0;
	rep(i, a.size()) {
		repa(j, last, a[i] - 1) {
			


		pre.assign(120, vector<ll> (120));
		repa(j1, j, 118)
			pre[j1][0] = 1;
		for (int i1 = 1; i1 < 115; ++i1) {
			repa(j1, 1, 115) {
				pre[i1][j1] += pre[i1 - 1][j1];
				if (j1 - i1 >= 0) pre[i1][j1] += pre[i1][j1 - i1];
			}
		}
		ll t = pre[110][n - cur_sum - j];
		ans += t;

		}
		cur_sum += a[i];
		last = a[i];
	}

	cout << ans;

	return 0;
}