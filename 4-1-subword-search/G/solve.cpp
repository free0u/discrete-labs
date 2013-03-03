#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "search4"

#define SZ_ALP 26

class AC {
	struct vertex {
		int prev_leaf;
		bool leaf;
		int link;
		vector<int> next;
		int p;
		char pch;
		vector<int> go;

		vector<int> indexes_string;

		vertex(int k = SZ_ALP) {
			next.assign(k, -1);
			go.assign(k, -1);
			leaf = false;
			prev_leaf = -1;
		}
	};


public:
	vector<vertex> tree;
	int sz;

	AC() {
		vertex t;
		t.p = t.link = -1;
		sz = 0;
		tree.push_back(t);
	}

	void add_string(string const& s) {
		int cur = 0;
		for (int i = 0; i < s.length(); ++i) {
			char c = s[i] - 'a';
			if (tree[cur].next[c] == -1) {
				vertex t;
				t.link = -1;
				t.p = cur;
				t.pch = c;

				tree[cur].next[c] = tree.size();
				tree.push_back(t);
			}
			cur = tree[cur].next[c];
		}
		tree[cur].leaf = true;
		tree[cur].indexes_string.push_back(sz);
		++sz;
	}

	int get_link(int v) {
		if (tree[v].link == -1) {
			if (v == 0 || tree[v].p == 0) {
				tree[v].link = 0;
			} else
			{
				tree[v].link = go(get_link(tree[v].p), tree[v].pch);
			}
		}
		return tree[v].link;
	}

	int go(int v, char c) {
		if (tree[v].go[c] == -1) {
			if (tree[v].next[c] != -1) {
				tree[v].go[c] = tree[v].next[c];	
			} else
			{
				if (v == 0) {
					tree[v].go[c] = 0;
				} else
				{
					tree[v].go[c] = go(get_link(v), c);
				}
			}
		}
		return tree[v].go[c];
	}

	int prev_leaf(int v) {
		if (tree[v].prev_leaf == -1) {
			if (v == 0) {
				tree[v].prev_leaf = 0;
			} else 
			{
				int prev = get_link(v);
				if (tree[prev].leaf) {
					tree[v].prev_leaf = prev;
				} else 
				{
					tree[v].prev_leaf = prev_leaf(prev);
				}
			}			
		}
		return tree[v].prev_leaf;
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
	scanf("%d\n", &n);
	vector<string> S(n);
	
	for (int i = 0; i < n; ++i) {
		getline(cin, S[i]);
	}
	
	string text;
	cin >> text;

	AC tree;
	for (int i = 0; i < S.size(); ++i) {
		tree.add_string(S[i]);
	}

	vector<bool> ans(n, false);

	int cur = 0;
	for (int i = 0; i < text.size(); ++i) {
		char c = text[i] - 'a';

		cur = tree.go(cur, c);
		
		int cur_link = cur;
		while (true) {
			if (tree.tree[cur_link].leaf) {
				for (int j = 0; j < tree.tree[cur_link].indexes_string.size(); ++j) {
					int ind = tree.tree[cur_link].indexes_string[j];
					ans[ind] = true;
				}
			}

			if (cur_link == 0) break;
			cur_link = tree.prev_leaf(cur_link);
		}
	}

	for (int i = 0; i < ans.size(); ++i) {
		printf("%s\n", ans[i] ? "YES" : "NO");
	}

	return 0;
}