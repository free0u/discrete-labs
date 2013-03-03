#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "period"


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

	vector<int> pi = prefix_function(s);

	int k = s.size() - pi.back();

	printf("%d\n", s.size() % k == 0 ? k : s.size());


	return 0;
}