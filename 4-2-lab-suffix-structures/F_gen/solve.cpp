#pragma comment(linker, "/STACK:36777216")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;
#define task_name "count"

int main() {
	freopen("input.txt", "w", stdout);

	srand(time(NULL));

	int N = 1000;

	string s = "";
	for (int i = 0; i < N; ++i) {
		int r = rand() % 26;
		char c = (char)(r + 'a');
		s += c;
	}

	cout << s;


	return 0;
}