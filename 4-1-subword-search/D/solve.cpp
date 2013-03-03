#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "z"

vector<int> z_function(string const& s) {
	int len = s.length();
	vector<int> res(len);
	int l, r;
	l = r = 0;
	for (int i = 1; i < len; ++i) {
		if (i <= r) {
			res[i] = min(r - i + 1, res[i - l]);
		}
		while (i + res[i] < len && s[res[i]] == s[i + res[i]]) {
			++res[i];
		}
		if (i + res[i] - 1 > r) {
			l = i;
			r = i + res[i] - 1;
		}
	}
	return res;
}

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
	vector<int> ans = z_function(s);
	for (int i = 1; i < ans.size(); ++i) {
		printf("%d ", ans[i]);
	}

	return 0;
}