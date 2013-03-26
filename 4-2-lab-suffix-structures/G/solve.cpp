#pragma comment(linker, "/STACK:36777216")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "refrain"

class SuffixTree {
	class Node;

	string alp;
	int alp_size;
	Node * root;
	int len_str;
	string str;

	struct Node {
		int depth;
		int start, end;
		vector<Node*> children;
		Node * parent;
		Node * suffix_link;

		int cnt_substring;

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
		str = s;
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

	void _dump(Node * cur, int d) {
		for (char f = 0; f < alp_size; ++f) {
			if (cur->children[f] != NULL) {
				for (int i = 0; i < d; ++i) cout << "  ";
				printf("%c: %d %d | %d\n", alp[f], cur->children[f]->start, cur->children[f]->end - 1, cur->children[f]->cnt_substring);
				_dump(cur->children[f], d + 1);
			}
		}
	}
	
	long long ref_len, ref_start, ref_cnt;
	Node * end_ref;
	void calculate_cnt(Node * cur) {
		if (cur->end == len_str) {
			cur->cnt_substring = 1;
			return;
		}

		int sum = 0;
		for (char f = 0; f < alp_size; ++f) {
			Node * c = cur->children[f];
			if (c == NULL) continue;
			calculate_cnt(c);
			sum += (c->cnt_substring);
		}
		cur->cnt_substring = sum;
	}

	void _find_refrain(Node * cur) {
		if (cur == NULL) return;
		for (char f = 0; f < alp_size; ++f) {
			Node * c = cur->children[f];
			if (c == NULL) continue;

			long long cur_len = c->depth;
			cur_len = cur_len + c->end - c->start;
			if (c->end == len_str) {
				cur_len--;
			}
			long long r = cur_len * c->cnt_substring;

			long long r_old = ref_len * ref_cnt;

			if (r > r_old) {
				ref_len = cur_len;
				ref_cnt = c->cnt_substring;
				end_ref = c;
			}

			_find_refrain(c);
		}
	}

	int find_refrain() {
		ref_len = ref_start = ref_cnt = 0;
		
		calculate_cnt(root);
		_find_refrain(root);

		cout << ref_len * ref_cnt << endl;
		cout << ref_len << endl;
		
		vector<string> ss;
		while (end_ref) {
			int ind_end = end_ref->end;
			if (ind_end == len_str) {
				--ind_end;
			}
			ss.push_back(str.substr(end_ref->start, ind_end - end_ref->start));
			end_ref = end_ref->parent;
		}
		for (int i = ss.size() - 1; i >= 0; --i) {
			for (int j = 0; j < ss[i].size(); ++j) {
				printf("%d ", ss[i][j] - 'a' + 1);
			}
		}

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
	
	string s = "";
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		s += (char)('a' + x - 1);
	}

	s += '$';
	SuffixTree t(s);

	t.find_refrain();
	return 0;
}