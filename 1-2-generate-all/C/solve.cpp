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

int n, k;
vi used;

int gen(int x, int l) {
	if (l == k) {
		rep(i, n) {
			if (used[i]) cout << i + 1 << " ";
		}
		cout << endl;
		re 0;
	}
	if (x >= n) re 0;
	used[x] = true;
	gen(x + 1, l + 1);

	used[x] = false;
	gen(x + 1, l);
}

int main() {
	freopen("choose.in", "r", stdin);
	freopen("choose.out", "w", stdout);

	cin >> n >> k;
	used.resize(n);

	gen(0, 0);
	

	return 0;
}