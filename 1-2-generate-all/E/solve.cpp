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

int gen(int s, int m) {
	if (s == n) {
		rep(i, a.size()) {
			cout << a[i];
			if (i < a.size() - 1) cout << "+";
		}
		cout << endl;
		re 0;
	}
	repa(i, m, n - s) {
		a.push_back(i);
		gen(s + i, i);
		a.pop_back();
	}
	re 0;
}

int main() {
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);

	cin >> n;
	gen(0, 1);

	return 0;
}