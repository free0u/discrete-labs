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

#define task_name "num2choose"


vector<vector<ll> > choose;

void calc_choose(int n) {
	++n;
	choose.assign(n, vector<ll> (n));
	rep(i, n) {
		choose[i][0] = 1;
	}
	rep(i, n) rep(j, n) {
		if (i * j == 0) continue;
		choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
	}
}

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	
	ll n, k, m;
	cin >> n >> k >> m;

	calc_choose(n);

	vi ans(k);
	vector<bool> used(n);
	int last = 0;
	rep(i, k) {
		repa(j, last + 1, n) {
			ll t = choose[n - j][k - i - 1];
			if (m >= t) {
				m -= t;
			} else {
				ans[i] = j;
				last = j;
				break;
			}
		}
	}

	rep(i, k) cout << ans[i] << " ";
	return 0;
}