#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "prefix"

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
	
	string s;
	cin >> s;

	vector<int> ans = prefix_function(s);
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d ", ans[i]);
	}

	return 0;
}