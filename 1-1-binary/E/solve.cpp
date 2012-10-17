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
	freopen("telemetry.in", "r", stdin);
	freopen("telemetry.out", "w", stdout);

	int n, k;
	cin >> n >> k;

	int l = pow((double)k, (double)n);
	vector<vector<int> > a(l, vector<int> (n));
	int cnt = k; // кол-во элементов в блоке
	for (int col = 0; col < n; ++col) {
		for (int row = 0; row < l; ++row) {		
			int t = row / cnt; // Номер блока
			a[row][col] = row % (cnt) / (cnt / k);
			if (t & 1) {
				a[row][col] = k - a[row][col] - 1;
			}
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