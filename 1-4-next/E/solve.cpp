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

#define task_name "nextbrackets"

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	string s;
	cin >> s;
	int n = s.length();
	vi a(n);
	int t = 0;
	rep(i, n) {
		if (s[i] == '(') ++t;
		if (s[i] == ')') --t;
		a[i] = t;
	}
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == ')') continue;
		int r = n - i - 1;
		int l = n - r;
		
		int lb = a[l - 1] - 2; // lb = left balance
		if (lb < 0) continue;

		int t = r - lb;
		int t2 = t / 2;
		if (t % 2 == 0) {
			s[i] = ')';
			rep(j, t2) {
				s[i + j + 1] = '(';
				s[i + j + t2 + 1] = ')';
			}
			rep(j, lb) s[n - j - 1] = ')';
			cout << s;

			re 0;
		}

	}

	cout << "-";

	return 0;
}