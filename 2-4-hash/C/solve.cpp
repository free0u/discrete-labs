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

#define task_name "linkedmap"


struct Item {
	string key, value, prev, next;
	Item() {}
	Item(string key, string value, string prev, string next) : key(key), value(value), prev(prev), next(next) {}

};


class Map {
	vector< vector<Item> > table;
	vector<unsigned> st;
	unsigned base;
	string last;

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
		last = "none";
	}

	void put(string const& key, string const& value) {
		unsigned h = hash(key);
		bool exist = false;
		for (int i = 0; i < table[h].size(); ++i) {
			if (table[h][i].key == key) {
				table[h][i].value = value;
				exist = true;
				break;
			}
		}
		if (!exist) {
			table[h].push_back(Item(key, value, last, "none"));
			if (last != "none") {
				unsigned h2 = hash(last);
				for (int i = 0; i < table[h2].size(); ++i) {
					if (table[h2][i].key == last) {
						table[h2][i].next = key;
						break;
					}
				}
			}
			last = key;
		}
	}

	void del(string const& key) {
		unsigned h = hash(key);
		for (int i = 0; i < table[h].size(); ++i) {
			if (table[h][i].key == key) {
				if (table[h].back().key != key) {
					swap(table[h].back(), table[h][i]);
				}

				string key_prev = table[h].back().prev;
				string key_next = table[h].back().next;

				if (key_prev != "none") {
					unsigned h2 = hash(key_prev);
					for (int i = 0; i < table[h2].size(); ++i) {
						if (table[h2][i].key == key_prev) {
							table[h2][i].next = key_next;
							break;
						}
					}
				}

				if (key_next != "none") {
					unsigned h2 = hash(key_next);
					for (int i = 0; i < table[h2].size(); ++i) {
						if (table[h2][i].key == key_next) {
							table[h2][i].prev = key_prev;
							break;
						}
					}
				}
				if (last == key) {
					last = table[h].back().prev;
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
			if (table[h][i].key == key) {
				return table[h][i].value;
			}
		}
		return "none";
	}

	string prev(string const& key) {
		unsigned h = hash(key);
		for (int i = 0; i < table[h].size(); ++i) {
			if (table[h][i].key == key) {
				return get(table[h][i].prev);
			}
		}
		return "none";
	}

	string next(string const& key) {
		unsigned h = hash(key);
		for (int i = 0; i < table[h].size(); ++i) {
			if (table[h][i].key == key) {
				return get(table[h][i].next);
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
		if (cmd == "prev") {
			cin >> key;
			cout << a.prev(key) << endl;
			continue;
		}
		if (cmd == "next") {
			cin >> key;
			cout << a.next(key) << endl;
			continue;
		}

		break;
	}
	

	return 0;
}