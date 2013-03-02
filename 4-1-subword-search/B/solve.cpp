#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "search2"

vector<int> prefix_function(string const& s) {
	int len = s.length();
	vector<int> res(len);
	for (int i = 1; i < len; ++i) {
		int j = res[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = res[j - 1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		res[i] = j;
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
	
	string s, t;
	cin >> s >> t;
	int n = s.length();
	int m = t.length();

	s += '#';
	s += t;
	vector<int> pi = prefix_function(s);

	vector<int> ans;
	for (int i = 0; i < pi.size(); ++i) {
		if (pi[i] == n) {
			ans.push_back(i - n - n + 1);
		}
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d ", ans[i]);
	}

	return 0;
}