#pragma comment(linker, "/STACK:36777216")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "tree"

class SuffixTree {
	class Node;

	string alp;
	int alp_size;
	Node * root;
	int len_str;

	struct Node {
		int depth;
		int start, end;
		vector<Node*> children;
		Node * parent;
		Node * suffix_link;

		Node(int _start, int _end, int _depth, Node * _parent, int _alp_size) {
			children.resize(_alp_size);
			start = _start;
			end = _end;
			parent = _parent;
			depth = _depth;
			suffix_link = NULL;
		}

		bool contains(int d) {
			return depth <= d && d < depth + (end - start);
		}
	};

	void init() {
		alp = "abcdefghijklmnopqrstuvwxyz$&";
		alp_size = alp.length();
	}


public:
	SuffixTree(string const& s) {
		init();

		len_str =s.length();
		build(s);
	}


	void build(string const& s) {
		int n = s.length();
		vector<char> a(n);
		for (int i = 0; i < n; ++i) {
			a[i] = alp.find(s[i]);
		}
		root = new Node(0, 0, 0, NULL, alp_size);
		Node * cn = root;
		root->suffix_link = root;
		Node * needs_suffix_link = NULL;
		int last_rule = 0;
		int j = 0;
		for (int i = -1; i < n - 1; ++i) {
			int cur = a[i + 1];
			for (; j <= i + 1; j++) {
				int cur_depth = i - j + 1;
				if (last_rule != 3) {
					cn = (cn->suffix_link != NULL ? cn->suffix_link : cn->parent->suffix_link);
					int k = j + cn->depth;
					while (cur_depth > 0 && !cn->contains(cur_depth - 1)) {
						k += cn->end - cn->start;
						cn = cn->children[a[k]];
					}
				}

				if (!cn->contains(cur_depth)) {
					if (needs_suffix_link != NULL) {
						needs_suffix_link->suffix_link = cn;
						needs_suffix_link = NULL;
					}
					if (cn->children[cur] == NULL) {
						cn->children[cur] = new Node(i + 1, n, cur_depth, cn, alp_size);
						last_rule = 2;
					} else {
						cn = cn->children[cur];
						last_rule = 3;
						break;
					}
				} else
				{
					int end = cn->start + cur_depth - cn->depth;
					if (a[end] != cur) {
						Node* newn = new Node(cn->start, end, cn->depth, cn->parent, alp_size);
						newn->children[cur] = new Node(i + 1, n, cur_depth, newn, alp_size);
						newn->children[a[end]] = cn;
						cn->parent->children[a[cn->start]] = newn;
						if (needs_suffix_link != NULL) {
							needs_suffix_link->suffix_link = newn;
						}
						cn->start = end;
						cn->depth = cur_depth;
						cn->parent = newn;
						cn = needs_suffix_link = newn;
						last_rule = 2;
					} else if (cn->end != n || cn->start - cn->depth < j) {
						last_rule = 3;
						break;
					} else {
						last_rule = 1;
					}
				}
			}
		}
		root->suffix_link = NULL;
	}

	void _dump(Node * cur, int& cnt) {
		int id = cnt;
		for (int i = 0; i < cur->children.size(); ++i) {
			Node * c = cur->children[i];
			if (c == NULL) continue;
			if (i == alp_size - 2) continue;
			int ind_end = c->end;
			printf("%d %d %d %d\n", id, ++cnt, c->start + 1, ind_end);
			_dump(c, cnt);
		}
	}

	void dump(int n) {
		int cnt = 1;
		_dump(root, cnt);
	}

	int _cnt_vertex(Node * cur) {
		int sum = 0;
		for (int i = 0; i < cur->children.size(); ++i) {
			Node * c = cur->children[i];
			if (c == NULL) continue;
			if (i == alp_size - 2) continue;
			sum += _cnt_vertex(c);
		}
		return sum + 1;
	}

	int cnt_vertex() {
		return _cnt_vertex(root);
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

	string s;
	cin >> s;

	SuffixTree tree(s);

	int n = tree.cnt_vertex();
	printf("%d %d\n", n, n - 1);
	tree.dump(s.length());

	return 0;
}