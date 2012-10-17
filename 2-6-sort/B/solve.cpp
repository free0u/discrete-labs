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

#define task_name "binsearch"

int binary_search_left(vector<int> &a, int x) {
	int l = -1;
	int r = a.size();
	while (r - l > 1) {
		int m = (r + l) / 2;
		if (a[m] < x) 
			l = m;
		else
			r = m;
	}
	if (r >= 0 && r < a.size())
		if (a[r] == x) 
			return r;
	return -1;
}

int binary_search_right(vector<int> &a, int x) {
	int l = -1;
	int r = a.size();
	while (r - l > 1) {
		int m = (r + l) / 2;
		if (a[m] <= x) 
			l = m;
		else
			r = m;
	}
	if (l >= 0 && l < a.size())
		if (a[l] == x) 
			return l;
	return -1;
}

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	int m, x;
	cin >> m;
	int l, r;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &x);
		l = binary_search_left(a, x);
		r = binary_search_right(a, x);
		if (l == -1) {
			printf("-1 -1\n");
			continue;
		}
		printf("%d %d\n", l + 1, r + 1);
	}

	return 0;
}