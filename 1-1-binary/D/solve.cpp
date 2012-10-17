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
	freopen("chaincode.in", "r", stdin);
	freopen("chaincode.out", "w", stdout);

	int n; 
	cin >> n;

	int l = 1 << n;
	int mask = l;

	set<int> a;
	int t = 0;
	
	for (int i = 0; i < l; ++i) {
		print(t, n);
		a.insert(t);

		t <<= 1;
		t &= ~mask;

		if (a.find(t | 1) == a.end()) {
			t |= 1;
			continue;
		}
		if (a.find(t) == a.end()) {
			continue;
		}
		break;
	}

	return 0;
}