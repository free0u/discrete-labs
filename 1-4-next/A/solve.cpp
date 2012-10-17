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

#define task_name "nextvector"

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
	int l = s.length();;
	string s2 = s;
	bool f;

	f = true;
	for (int i = l - 1; i >= 0; --i) {
		if (s[i] == '1') {
			s[i] = '0';
			repa(j, i + 1, l - 1) s[j] = '1';
			cout << s;
			f = false;
			break;
		}
	}
	if (f) cout << "-";

	cout << endl;
	s = s2;
	f = true;
	for (int i = l - 1; i >= 0; --i) {
		if (s[i] == '0') {
			s[i] = '1';
			repa(j, i + 1, l - 1) s[j] = '0';
			cout << s;
			f = false;
			break;
		}
	}

	if (f) cout << "-";
	return 0;
}