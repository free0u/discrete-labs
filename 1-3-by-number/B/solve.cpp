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

#define task_name "perm2num"

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vi per(n);
	rep(i, n) {
		cin >> per[i];
		per[i]--;
	}
	ll ans = 0;

	vector<bool> used(n);


	vector<ll> fact(20);
	fact[0] = 1;
	repa(i, 1, 19) fact[i] = i * fact[i - 1];

	rep(i, n) {
		rep(j, per[i]) {
			if (used[j]) continue;
			ans += fact[n - i - 1];
		}
		used[per[i]] = true;
	}
	cout << ans;

	return 0;
}