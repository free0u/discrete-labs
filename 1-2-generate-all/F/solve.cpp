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

vi a;
int n;

bool bit(int x, int i) {
	 re (x & (1 << i)) != 0;
}


bool comp(int a, int b) {

	int i, j;
	i = j = 0;

	while (true) {

		for (; i < n; ++i) {
			if (bit(a, n - i - 1)) {
				break;
			}
		}
		if (i == n) re 1;

		for (; j < n; ++j) {
			if (bit(b, n - j - 1)) {
				break;
			}
		}
		if (j == n) re 0;

		if (i < j) re 1;
		if (i > j) re 0;
		++i;
		++j;
	}

	re 0;
}

int main() {
	freopen("subsets.in", "r", stdin);
	freopen("subsets.out", "w", stdout);

	int l;

	cin >> n;
	l = pow(2.0, n);
	rep(i, l) a.push_back(i);
	sort(all(a), comp);
	rep(i, l) {
		int x = a[i];
		rep(j, n) 
			if (bit(x, n - j - 1)) 
				cout << j + 1 << " ";
		cout << endl;
	}

	return 0;
}