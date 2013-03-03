#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
#define task_name "search4"

#define SZ_ALP 26

class AC {
	struct vertex {
		int prev_leaf;
		bool leaf;
		int link;
		int next[SZ_ALP];
		char pch;
		int go[SZ_ALP];
		int p;

		vertex(int k = SZ_ALP) {
			memset(next, -1, sizeof next);
			memset(go, 255, sizeof go);

			leaf = false;
			prev_leaf = -1;
		}
	};


public:
	vector<vertex> tree;
	vector<int> indexes;
	int sz;

	AC(int n) {
		vertex t;
		t.p = t.link = -1;
		tree.push_back(t);

		sz = 0;
		indexes.assign(n, -1);
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
		indexes[sz] = cur;
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

	AC tree(n);
	for (int i = 0; i < S.size(); ++i) {
		tree.add_string(S[i]);
	}

	vector<int> ans(n, false);
	vector<bool> cond(tree.tree.size(), false);

	int cur = 0;
	for (int i = 0; i < text.size(); ++i) {
		char c = text[i] - 'a';

		cur = tree.go(cur, c);
		
		int cur_link = cur;
		while (true) {
			if (cond[cur_link]) {
				break;
			}

			if (tree.tree[cur_link].leaf) {
				cond[cur_link] = true;
			}

			if (cur_link == 0) break;
			cur_link = tree.prev_leaf(cur_link);
		}
	}

	for (int i = 0; i < S.size(); ++i) {
		printf("%s\n", cond[tree.indexes[i]] ? "YES" : "NO");
	}

	return 0;
}