#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "parking"

class DSU {
	vector<int> p, data;
	int n;
	int cnt;
public:
	DSU() {}
	DSU(int _n) {
		n = _n;
		cnt = 0;
		for (int i = 0; i < n; ++i) {
			p.push_back(i);
			data.push_back(i);
		}
	}

	int find(int x) {
		if (x != p[x]) 
			p[x] = find(p[x]);
		return p[x];
	}

	void unite(int x, int y, int slot = -1) {
		x = find(x);
		y = find(y);
		if (x != y) {
			if (rand() & 1) swap(x, y);
			p[y] = x;
			int s1 = data[x];
			int s2 = data[y];
			data[x] = (s1 == slot ? s2 : s1);
		}
	}
	int find_slot(int x) {
		x = find(x);
		return data[x];
	}
	int add(int x) {
		cnt++;
		int ind = find_slot(x);
		unite(ind, (ind + 1) % n, ind);
		return ind + 1;
	}
	int remove(int x) {
		--cnt;
		if (cnt + 1 == n) {
			for (int i = 0; i < n; ++i) {
				p[i] = x;
			}
			data[x] = x;
			return 0;
		}
		int sl, sr;
		sr = find_slot(x);
		sl = x;
		while (find_slot(sl) == sr) {
			sl--;
			if (sl < 0) {
				sl += n;
			}
			if (sl == sr) break;
		}
		if (sl < x) {
			for (int i = sl + 1; i <= x; i++) {
				p[i] = x;
			}
		} else
		{
			for (int i = sl + 1; i < n; ++i) {
				p[i] = x;
			}
			for (int i = 0; i <= x; ++i) {
				p[i] = x;
			}
		}
		data[x] = x;
		if (x <= sr) {
			for (int i = x + 1; i <= sr; i++) {
				p[i] = sr;
			}
		} else
		{
			for (int i = x + 1; i < n; ++i) {
				p[i] = sr;
			}
			for (int i = 0; i <= sr; ++i) {
				p[i] = sr;
			}
		}
		data[sr] = sr;
		return 0;
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
	
	int n, m, x;
	cin >> n >> m;
	DSU a(n);
	string s;
	char s2[10];
	for (int i = 0; i < m; ++i) {
		scanf("%s %d\n", s2, &x);
		if (s2[1] == 'n') {
			//cout << a.add(x - 1) << endl;
			printf("%d\n", a.add(x - 1));
		} else
		{
			a.remove(x - 1);
		}
	}

	return 0;
}