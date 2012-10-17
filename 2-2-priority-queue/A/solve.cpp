#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define task_name "isheap"

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
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int l, r;
	for (int i = 0; i < n; i++) {
		l = 2 * i + 1;
		r = l + 1;
		if (l < n) {
			if (a[i] > a[l]) {
				cout << "NO";
				return 0;
			}
		}
		if (r < n) {
			if (a[i] > a[r]) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}