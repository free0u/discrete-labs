#pragma comment(linker, "/STACK:128000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
#define task_name "chinese"

#include <time.h>

int main() {
	freopen("chinese.in", "w", stdout);

	srand(time(0));


	int MAX_W = 10;

	int n = 100;

	int cnt_e = n * (n - 1);
	cnt_e /= 2;

	int m = rand() & cnt_e;
	
	m = 1000;

	printf("%d %d\n", n, m);
	for (int i = 0; i < m; i++) {
		int from, to, w;
		while (true) {
			from = rand() % n + 1;
			to = rand() % n + 1;
			w = rand() % MAX_W;
			printf("%d %d %d\n", from, to, w);
			if (from == to) continue;

			break;
		}
	}
	
	return 0;
}