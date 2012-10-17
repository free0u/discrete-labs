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
#define repa(i, a, b) for (int i = (a); i <= (b); ++b)
#define sqr(x) ((x)*(x))
#define all(c) c.begin(), c.end()
#define re return

bool bit(int x, int i) {
	re (x & (1 << i));
}

bool isok(int x) {
	rep(i, 16) {
		if (bit(x, i) && bit(x, i + 1))
			re false;
	}
	re true;
}

int print(int x, int l) {
	rep(i, l) {
		cout << bit(x, l - i - 1);
	}
	re 0;
}

int main() {
	freopen("vectors.in", "r", stdin);
	freopen("vectors.out", "w", stdout);
	
	int n;
	cin >> n;
	int l = pow(2.0, n);
	int cnt = 0;
	rep(i, l) {
		if (isok(i)) {
			++cnt;
		}
	}
	cout << cnt << endl;
	rep(i, l) {
		if (isok(i)) {
			print(i, n);
			cout << endl;
		}
	}

	return 0;
}