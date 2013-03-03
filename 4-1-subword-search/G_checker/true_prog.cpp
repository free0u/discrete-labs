#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "search4"


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output_true.txt", "w", stdout);
	
	int n;
	scanf("%d\n", &n);
	vector<string> S(n);
	
	for (int i = 0; i < n; ++i) {
		getline(cin, S[i]);
	}
	
	string text;
	cin >> text;

	for (int i = 0; i < S.size(); ++i) {
		if (text.find(S[i]) != -1) {
			cout << "YES";
		} else
		{
			cout << "NO";
		}
		cout << endl;
	}

	return 0;
}