#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "trie"
#define ALP_SIZE 26

class suffix_trie {
	struct Node {
		bool leaf;
		vector<Node*> next;

		Node() {
			leaf = false;
			next.assign(ALP_SIZE, NULL);
		}

		~Node() {
			for (int i = 0; i < next.size(); ++i) {
				if (next[i] != NULL) {
					delete next[i];
				}
			}
		}
	};

	Node * root;
	int cnt_node;
public:
	suffix_trie() {
		root = new Node();
		cnt_node = 1;
	}


	~suffix_trie() {
		delete root;
	}

	void add(string const& s) {
		Node * cur = root;
		for (int i = 0; i < s.length(); ++i) {
			char c = s[i] - 'a';
			if (cur->next[c] == NULL) {
				cur->next[c] = new Node();
				++cnt_node;
			}
			cur = cur->next[c];
		}
		cur->leaf = true;
	}

	void _dump(Node * cur, int& cnt) {
		int id = cnt;
		for (int i = 0; i < cur->next.size(); ++i) {
			if (cur->next[i] != NULL) {
				printf("%d %d %c\n", id, ++cnt, (char)(i + 'a'));
				_dump(cur->next[i], cnt);
			}
		}
	}

	void dump() {
		printf("%d %d\n", cnt_node, cnt_node - 1);
		int cnt = 1;
		_dump(root, cnt);
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

	suffix_trie trie;

	int len = s.length();
	for (int i = 0; i < len; ++i) {
		trie.add(s.substr(i, len - i));
	}

	trie.dump();

	return 0;
}