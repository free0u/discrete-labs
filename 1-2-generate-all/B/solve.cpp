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

int used[8];
int per[8];
int n;

int gen(int l) {
	if (n == l) {
		rep(i, n) cout << per[i] + 1 << " ";
		cout << endl;
	} else
	{
		rep(i, n) {
			if (used[i]) continue;
			used[i] = true;
			per[l] = i;
			gen(l + 1);
			used[i] = false;
		}
	}
	re 0;
}


int main() {
	freopen("permutations.in", "r", stdin);
	freopen("permutations.out", "w", stdout);

	cin >> n;
	gen(0);
	

	return 0;
}