#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repa(i, a, b) for (int i = (a); i <= (b); ++i)
#define sqr(x) ((x)*(x))
#define all(c) c.begin(), c.end()
#define re return

#define task_name "set"

class Set {
	vector< vector<int> > table;
	unsigned base;
	unsigned hash(int value) {
		return value % base;
	}
public:
	Set(unsigned _base) {
		base = _base;
		table.resize(base);
	}

	void insert(int value) {
		unsigned h = hash(value);
		bool exist = false;
		for (size_t i = 0; i < table[h].size(); ++i) {
			if (table[h][i] == value) {
				exist = true;
				break;
			}
		}
		if (!exist) {
			table[h].push_back(value);
		}
	}

	void del(int value) {
		unsigned h = hash(value);
		for (size_t i = 0; i < table[h].size(); ++i) {
			if (table[h][i] == value) {
				if (table[h].back() != value) {
					swap(table[h][i], table[h].back());
				}
				table[h].pop_back();
				break;
			}
		}
	}

	bool exists(int value) {
		unsigned h = hash(value);
		for (size_t i = 0; i < table[h].size(); ++i) {
			if (table[h][i] == value) return true;
		}
		return false;
	}
};


int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Set a(1000000);

	char cmd[10];
	int x;
	while (scanf("%s%d\n", cmd, &x) != -1) {
		if (cmd[0] == 'i') {
			a.insert(x);
			continue;
		}
		if (cmd[0] == 'd') {
			a.del(x);
			continue;
		}
		if (cmd[0] == 'e') {
			printf("%s\n", a.exists(x) ? "true" : "false");
			continue;
		}
		break;
	}
	

	return 0;
}