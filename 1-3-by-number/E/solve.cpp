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

#define task_name "num2brackets"

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ll n, k;
	cin >> n >> k;
	n *= 2;
	vector<vector<ll> > dp(n + 1, vector<ll> (n + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		rep(j, n + 1) {
			ll a = (j > 0 ? dp[i - 1][j - 1] : 0);
			ll b = (j < n ? dp[i - 1][j + 1] : 0);
			dp[i][j] = a + b;
		}

	}

	string ans = "";
	ll dep = 0;
	k++;
	for (int i = n - 1; i >= 0; --i) {
		if (dep + 1 <= n && dp[i][dep + 1] >= k) {
			ans += '(';
			++dep;
		}
		else {
			ans += ')';
			if (dep + 1 <= n)
				k -= dp[i][dep + 1];
			--dep;
		}
	}
	cout << ans;

	return 0;
}