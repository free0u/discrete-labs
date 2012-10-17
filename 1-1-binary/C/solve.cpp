#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repa(i, a, b) for (int i = (a); i <= (b); ++b)
#define sqr(x) ((x)*(x))
#define all(c) c.begin(), c.end()
#define re return

int bit(int x, int i) {
	return (x & 1 << i) != 0;
}

void print(int x, int l) {
	for (int i = 0; i < l; ++i) {
		cout << bit(x, l - i - 1);
	}
	cout << endl;
}



int main() {
	freopen("antigray.in", "r", stdin);
	freopen("antigray.out", "w", stdout);

	int n, k;
	cin >> n;
	k = 3;

	int l = pow((double)k, (double)n);
	vector<vector<int> > a(l, vector<int> (n));
	
	int m[3][3] = {
		{0, 1, 2},
		{1, 2, 0},
		{2, 0, 1}
	};

	for (int i = 0; i < 3; ++i) a[i][0] = i;
	int cnt = 9;
	for (int col = 1; col < n; ++col) {
		for (int j = 0; j < cnt; ++j) {
			a[j][col] = m[j / (cnt / 3)][j % 3];
		}
		cnt *= k;
	}

	
	cnt = 3;
	for (int col = 0; col < n; ++col) {
		for (int j = cnt; j < l; ++j) {
			a[j][col] = a[j - cnt][col];
		}

		cnt *= k;
	}

	

	for (int row = 0; row < l; ++row) {
		for (int col = 0; col < n; ++col) {
			printf("%d", a[row][col]);
		}
		printf("\n");
	}

	return 0;
}