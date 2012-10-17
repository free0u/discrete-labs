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

#define task_name "nextsetpartition"

vector<vector<ll> > pre(31, vector<ll> (31));

int calc_choose2(int n, int k) {
	ll ans = 1;
	repa(i, n - k + 1, n) ans *= i;
	repa(i, 1, k) ans /= i;
	re ans;
}

int calc_choose(int n, int k) {
	if (n < k) re 0;
	if (n == k || k == 0) re 1;
	if (n <= 16) re calc_choose2(n, k);
	re calc_choose(n - 1, k - 1) + calc_choose(n - 1, k);
}



int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	while (true) {
		cin >> n >> k;
		if (n == 0 && k == 0) break;

	}

	return 0;
}