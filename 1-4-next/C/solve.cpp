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

#define task_name "nextchoose"

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	vi a(k);
	rep(i, k) cin >> a[i];

	for (int i = k - 1; i >= 0; --i) {
		int t = a[i] + 1;
		if (n - t >= k - i - 1) {
			a[i] = t;
			repa(j, i + 1, k - 1) a[j] = a[j - 1] + 1;
			rep(j, k) cout << a[j] << " ";
			re 0;
		}
	}

	cout << -1;

	return 0;
}