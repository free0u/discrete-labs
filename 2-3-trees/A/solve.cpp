#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define task_name "bstsimple"

const int inf = 1e9 + 31;

struct Node {
	int value;
	Node *left, *right;
	Node() {}
	Node(int x, Node *L = NULL, Node *R = NULL) {
		value = x;
		left = L; right = R;
	}
	~Node() {
		if (left) delete left;
		if (right) delete right;
	}
};

class BST {
private:
	Node *root;
public:
	BST() {
		root = NULL;
	}
	~BST() {
		if (root) delete root;
	}
	int insert(int value) {
		Node *new_node = new Node(value);
		if (root == NULL) {
			root = new_node;
			return 0;
		}

		Node *x = root, *prev;
		while (x != NULL) {
			prev = x;
			if (value < x->value) {
				x = x->left;
			} else
			{
				x = x->right;
			}
		}

		if (value < prev->value) {
			prev->left = new_node;
		} else
		{
			prev->right = new_node;
		}
		return 0;
	}

	bool exists(int value) {
		Node *x = root;
		while (x != NULL) {
			if (value == x->value) return true;
			if (value < x->value)
				x = x->left;
			else
				x = x->right;
		}
		return false;
	}

	int del(int value) {
		Node *x = root, *prev = NULL;
		while (x != NULL) {
			if (value == x->value) break;
			
			prev = x;
			if (value < x->value) {
				x = x->left;
			} else
			{
				x = x ->right;
			}
		}
		if (x == NULL) return 0;

		// лист
		if (x->left == NULL && x->right == NULL) {
			// в дереве лишь одно значение -- корень
			if (prev == NULL) {
				delete root;
				root = NULL;
				return 0;
			}

			if (prev->left == x) 
				prev->left = NULL;
			if (prev->right == x)
				prev->right = NULL;
			delete x;
			return 0;
		}
		// нет левого
		if(x->left == NULL) {
			if (prev == NULL) {
				root = root->right;
				x->left = x->right = NULL;	
				delete x;
				return 0;
			}
			if (prev->left == x) {
				prev->left = x->right;
			} else
			{
				prev->right = x->right;
			}
			x->left = x->right = NULL;	
			delete x;
			return 0;
		}
		// нет правого
		if(x->right == NULL) {
			if (prev == NULL) {
				root = root->left;
				x->left = x->right = NULL;	
				delete x;
				return 0;
			}
			if (prev->left == x) {
				prev->left = x->left;
			} else
			{
				prev->right = x->left;
			}
			x->left = x->right = NULL;	
			delete x;
			return 0;
		}
		Node *right_min = x->right;
		prev = NULL;
		while (right_min->left) {
			prev = right_min;
			right_min = right_min->left;
		}
		if (prev == NULL) {
			x->right = right_min->right;
		} else
		{
			prev->left = right_min->right;
		}
		x->value = right_min->value;
		right_min->left = right_min->right = NULL;
		delete right_min;
		return 0;
	}

		bool next(int value, int &ret) {
			if (root == NULL) return false;
		
		ret = inf;
		
		Node *x = root;

		while (x != NULL) {
			if (x->value > value && x->value < ret)
				ret = x->value;
			if (value < x->value)
				x = x->left;
			else
				x = x->right;
		}
		if (ret == inf) return false;
		return true;
	}
	bool prev(int value, int &ret) {
		if (root == NULL) return false;
		
		ret = -inf;
		
		Node *x = root;

		while (x != NULL) {
			if (x->value < value && x->value > ret)
				ret = x->value;
			if (value <= x->value)
				x = x->left;
			else
				x = x->right;
		}
		if (ret == -inf) return false;
		return true;
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
	
	char buf[10], c;
	int x, res;
	bool st;

	BST tree;

	while (scanf("%s %d\n", buf, &x) != -1) {
		c = buf[0];
		if (c == 'i') { // insert
			if (!tree.exists(x)) tree.insert(x);
			continue;
		}
		if (c == 'd') { // delete
			tree.del(x);
			continue;
		}
		if (c == 'e') { // exists
			bool res = tree.exists(x);
			printf("%s\n", res ? "true" : "false");
			continue;
		}
		if (c == 'n') { // next
			st = tree.next(x, res);
			if (st)
				printf("%d\n", res);
			else
				printf("none\n");
			continue;
		}
		if (c == 'p') { // prev
			st = tree.prev(x, res);
			if (st)
				printf("%d\n", res);
			else
				printf("none\n");
			continue;
		}
		if (c == 'q') return 0;

	}

	return 0;
}