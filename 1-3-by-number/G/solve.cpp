#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repa(i, a, b) for (int i = (a); i <= (b); ++i)
#define sqr(x) ((x)*(x))
#define all(c) c.begin(), c.end()
#define re return

#define task_name "num2brackets2"

inline ll pow(ll a, ll b) {
	re pow((double)a, (double)b);
}

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
	dp[n][0] = 1;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j > 0; --j) {
			dp[i][j] = dp[i + 1][j - 1] + dp[i + 1][j + 1];
		}
		dp[i][0] = dp[i + 1][1];
	}

	int dep = 0;
	stack<int> st;

	++k;
	rep(i, n) {
		if (dep + 1 <= n) {
			if (dp[i + 1][dep + 1] * pow(2, (n - i - 2 - dep) / 2) >= k) {
				cout << "(";
				st.push(0);
				++dep;
				continue;
			} else
			{
				k -= dp[i + 1][dep + 1] * pow(2, (n - i - 2 - dep) / 2);
			}
		}
		if (dep > 0 && !st.empty()) {
			if (st.top() == 0) {
				if (dp[i + 1][dep - 1] * pow(2, (n - i - dep) / 2) >= k) {
					cout << ")";
					--dep;
					if (!st.empty()) st.pop();
					continue;
				} else
				{
					k -= dp[i + 1][dep - 1] * pow(2, (n - i - dep) / 2);
				}
			}
		}
		if (dep + 1 <= n) {
			if (dp[i + 1][dep + 1] * pow(2, (n - i - 2 - dep) / 2) >= k) {
				cout << "[";
				st.push(2);
				++dep;
				continue;
			} else
			{
				k -= dp[i + 1][dep + 1] * pow(2, (n - i - 2 - dep) / 2);
			}
		}
		cout << "]";
		--dep;
		if (!st.empty()) st.pop();
	}

	return 0;
}