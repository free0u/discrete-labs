#pragma comment(linker, "/STACK:36777216")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "count"


#include <set>

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

	set<string> data;

	int n = s.length();
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= n - i; ++j) {
			data.insert(s.substr(i, j));
		}
	}

	cout << data.size();

	return 0;
}