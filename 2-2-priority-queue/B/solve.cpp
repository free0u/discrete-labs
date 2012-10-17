#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

#define task_name "dsu"

class DSU {
	vector<int> p, dmin, dmax, dcnt;
public:
	DSU(int n) {
		for (int i = 0; i < n; ++i) {
			p.push_back(i);
			dmin.push_back(i);
			dmax.push_back(i);
			dcnt.push_back(1);
		}
	}
	int find(int x) {
		if (x != p[x])
			p[x] = find(p[x]);
		return p[x];
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x != y) {
			if (rand() & 1) swap(x, y);
			p[y] = x;
			dcnt[x] += dcnt[y];
			dmin[x] = min(dmin[x], dmin[y]);
			dmax[x] = max(dmax[x], dmax[y]);
		}
	}
	void print(int x) {
		x = find(x);
		printf("%d %d %d\n", dmin[x] + 1, dmax[x] + 1, dcnt[x]);
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
	
	int n;
	cin >> n;
	getchar();
	DSU a(n);
	string s, cmd;
	int x, y;	
	while (getline(cin, s)) {
		stringstream ss(s);
		ss >> cmd;
		if (cmd == "union") {
			ss >> x >> y;
			x--; y--;
			a.unite(x, y);
		} else
		{
			ss >> x;
			x--;
			a.print(x);
		}
	}

	return 0;
}