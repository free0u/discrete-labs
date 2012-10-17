#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define task_name "antiqs"

#include <time.h>

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	srand(time(0));

	vector<int> aa(100);
	for (int i = 0; i < 1e8; i++) {
		aa[rand() % 100]++;
	}

	int n;
	cin >> n;
	
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	if (n == 2) {
		printf("1 2\n");
		return 0;
	}

	vector<int> a(n);
	a[0] = 2;
	a[1] = 1;
	a[2] = 3;

	for (int i = 3; i < n; ++i) {
		a[i] = i + 1;
	}
	for (int i = 3; i < n; ++i) {
		swap(a[i], a[i / 2]);
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}

	return 0;
}