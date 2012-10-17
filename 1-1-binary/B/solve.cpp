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

int bit(int x, int i) {
	return (x & 1 << i) != 0;
}

int main() {
	freopen("gray.in", "r", stdin);
	freopen("gray.out", "w", stdout);

	int n; 
	cin >> n;
	
	int l = 1 << n;
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << bit((i ^ (i >> 1)), n - j - 1);
		}
		cout << endl;
	}
	

	return 0;
}