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

#define task_name "map"

class Map {
	vector< vector<pair<string, string> > > table;
	vector<unsigned> st;
	unsigned base;
	unsigned hash(string const& s) {
		unsigned ret = 0;
		for (int i = 0; i < s.length(); ++i) {
			ret += s[i] * st[i];
		}
		return ret % base;
	}
public:
	Map(unsigned _base) {
		base = _base;
		table.resize(base);

		st.resize(25);
		st[0] = 1;
		for (int i = 1; i < st.size(); ++i) {
			st[i] = st[i - 1] * 31;
		}
	}

	void put(string const& key, string const& value) {
		unsigned h = hash(key);
		bool exist = false;
		for (int i = 0; i < table[h].size(); ++i) {
			if (table[h][i].first == key) {
				table[h][i].second = value;
				exist = true;
				break;
			}
		}
		if (!exist) {
			table[h].push_back(make_pair(key, value));
		}
	}

	void del(string const& key) {
		unsigned h = hash(key);
		for (int i = 0; i < table[h].size(); ++i) {
			if (table[h][i].first == key) {
				if (table[h].back().first != key) {
					swap(table[h].back(), table[h][i]);
				}
				table[h].pop_back();
				break;
			}
		}
	}

	string get(string const& key) {
		unsigned h = hash(key);
		bool exist = false;
		for (int i = 0; i < table[h].size(); ++i) {
			if (table[h][i].first == key) {
				return table[h][i].second;
			}
		}
		return "none";
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

	Map a(1e6);

	string cmd, key, value;
	int x;
	while (cin >> cmd) {
		if (cmd == "put") {
			cin >> key >> value;
			a.put(key, value);
			continue;
		}
		if (cmd == "delete") {
			cin >> key;
			a.del(key);
			continue;
		}
		if (cmd == "get") {
			cin >> key;
			cout << a.get(key) << endl;
			continue;
		}
		break;
	}
	

	return 0;
}