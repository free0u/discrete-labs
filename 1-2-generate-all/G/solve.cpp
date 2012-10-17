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

vector<vi> a;

int gen(int x, int cur_cnt) {
	if (x == n) {
		if (cur_cnt == k) {
			rep(i, cur_cnt) {
				rep(j, a[i].size()) {
					cout << a[i][j] + 1 << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		re 0;
	}
	rep(i, cur_cnt) {
		a[i].push_back(x);
		gen(x + 1, cur_cnt);
		a[i].pop_back();
	}
	if (cur_cnt < k) {
		a[cur_cnt].push_back(x);
		gen(x + 1, cur_cnt + 1);
		a[cur_cnt].pop_back();
	}
	re 0;
}


int main() {
	freopen("part2sets.in", "r", stdin);
	freopen("part2sets.out", "w", stdout);

	cin >> n >> k;
	a.resize(n);
	gen(0, 0);


	return 0;
}