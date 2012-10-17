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

#define task_name "num2part"


vector<vector<ll> > pre;

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

	vector<ll> ans;
	
	ll cur_sum = 0;
	ll last = 1;

	while (cur_sum < n) {
		for (int i = last; i <= n; ++i) {
			if (cur_sum + i <= n) {
				pre.assign(120, vector<ll> (120));
				repa(j1, i, 118)
					pre[j1][0] = 1;
				for (int i1 = 1; i1 < 115; ++i1) {
					repa(j1, 1, 115) {
						pre[i1][j1] += pre[i1 - 1][j1];
						if (j1 - i1 >= 0) pre[i1][j1] += pre[i1][j1 - i1];
					}
				}
				ll t = pre[110][n - cur_sum - i];

				if (k >= t) {
					k -= t;
					continue;
				}
				ans.push_back(i);
				cur_sum += i;
				last = i;
				break;
			}
		}
	}
	rep(i, ans.size() - 1) cout << ans[i] << "+";
	cout << ans.back();


	return 0;
}