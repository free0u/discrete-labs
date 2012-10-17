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

int n;
vi a;

int gen(int x, int bal) {
	if (x == n) {
		if (bal ==0) {
			rep(i, n) cout << (a[i] ? '(' : ')');
			cout << endl;
		}
		re 0;
	}
	a[x] = 1;
	gen(x + 1, bal + 1);
	if (bal > 0) {
		a[x] = 0;
		gen(x + 1, bal - 1);
	}
	re 0;
}

int main() {
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);

	cin >> n;
	n *= 2;
	a.resize(n);
	gen(0, 0);
	

	return 0;
}