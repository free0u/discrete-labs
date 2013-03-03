#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;
#define task_name "search4"

int main() {
	freopen("input.txt", "w", stdout);

	
	srand(time(NULL));

	string text = "";

	for (int i = 0; i < 10; ++i) {
		text += (char)('a' + rand() % 26);
	}

	int len = text.length();


	vector<string> S;
	for (int i = 0; i < len; ++i) {
		for (int j = 1; j < len; ++j) {
			if (i + j < len) {
				S.push_back(text.substr(i, j));
			}
		}
	}

	for (int i = 0; i < 50; ++i) {
		string t = "";
		for (int j = 0; j < 20; ++j) {
			t += (char)('a' + rand() % 26);
		}
		S.push_back(t);
	}
	random_shuffle(S.begin(), S.end());

	cout << S.size() << endl;
	for (int i = 0; i < S.size(); ++i) {
		cout << S[i] << endl;
	}
	cout << text;

	return 0;
}