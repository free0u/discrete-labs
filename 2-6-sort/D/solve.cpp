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

#define task_name "garland"

const double eps = 1e-8;

void calc_h(vector<double> &h, double A, double B) {
	h[0] = A;
	h[1] = B;
	double cur;
	for (int i = 2; i < h.size(); ++i) {
		cur = h[i - 1] + 1;
		cur = cur * 2 - h[i - 2];
		h[i] = cur;
	}
}

bool is_ok(vector<double> &h) {
	for (int i = 0; i < h.size(); ++i) {
		if (h[i] > eps) continue;
		return false;
	}
	return true;
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
	double A;
	cin >> A;

	vector<double> h(n);
	

	double l = A;
	double r = 0;
	for (int i = 0; i < 100; ++i) {
		double m = (l + r) / 2;
		calc_h(h, A, m);
		if (is_ok(h)) {
			l = m;
		} else
		{
			r = m;
		}
	}
	printf("%.5f", h.back());

	return 0;
}