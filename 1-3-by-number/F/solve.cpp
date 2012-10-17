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

#define task_name "brackets2num"

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	string s;
	cin >> s;
	int n = s.length();
	ll ans = 0;
	int dep = 0;

	vector<vector<ll> > dp(n + 1, vector<ll> (n + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		rep(j, n + 1) {
			ll a = (j > 0 ? dp[i - 1][j - 1] : 0);
			ll b = (j < n ? dp[i - 1][j + 1] : 0);
			dp[i][j] = a + b;
		}

	}

	rep(i, n) {
		if (s[i] == '(') {
			++dep;
			continue;
		}
		ans += dp[n - i - 1][dep + 1];
		--dep;
	}
	cout << ans;

	return 0;
}