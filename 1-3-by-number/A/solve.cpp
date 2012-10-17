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

#define task_name "num2perm"

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
	vector<ll> ans(n);
	vector<ll> used(n);
	vector<ll> fact(20);
	fact[0] = 1;
	repa(i, 1, 19) fact[i] = i * fact[i - 1];

	rep(i, n) {
		rep(j, n) {
			if (used[j]) continue;
			if (k >= fact[n - i - 1]) {
				k -= fact[n - i - 1];	
			} else
			{
				ans[i] = j;
				used[j] = true;
				break;
			}
		}
	}
	rep(i, n) cout << ans[i] + 1 << " ";

	return 0;
}