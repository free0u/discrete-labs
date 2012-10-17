#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <time.h>


using namespace std;
typedef long long ll;


#define task_name "rmq2"

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "w", stdout);
#endif
	
	int n = 10;

	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		cout << (1) << " ";
	}
	cout << endl;
	srand(time(0));

	int nn = 100;
	int t;
	int x, y, z;
	for (int i = 0; i < nn; ++i) {
		t = rand() % 3;
		if (t == 0) {
			cout << "min ";

			x = rand() % n;
			y = rand() % n;
			if (x > y) swap(x, y);
			cout << x + 1 << " " << y + 1;

			cout << endl;
		}

		if (t == 1) {
			cout << "set ";

			x = rand() % n;
			y = rand() % n;
			if (x > y) swap(x, y);
			cout << x + 1 << " " << y + 1 << " " << (rand() % 10);

			cout << endl;
		}
		if (t == 2) {
			cout << "add ";

			x = rand() % n;
			y = rand() % n;
			if (x > y) swap(x, y);
			cout << x + 1 << " " << y + 1 << " " << (rand() % 10);

			cout << endl;
		}
	}

	return 0;
}