// Только рефакторинг по сравнению с первой посылкой по задаче!


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define task_name "bst"

const int inf = 1e9 + 31;

enum Color {BLACK, RED};

struct Node {
	Node *left, *right, *prev;
	Color color;
	int value;
	bool isLeaf;

	Node(int val = -1, Node* L = NULL, Node* R = NULL, Node* parent = NULL, Color col = BLACK, bool leaf = false) {
		value = val;
		left = L;
		right = R;
		prev = parent;
		color = col;
		isLeaf = leaf;
	}


	~Node() {
		if (left) delete left;
		if (right) delete right;
	}
	void make_leaf(Node* parent = NULL) {
		left = right = NULL;
		prev = parent;
		color = BLACK;
		isLeaf = true;
	}
	void add_leafs() {
		left = new Node();
		left->make_leaf(this);
		right = new Node();
		right->make_leaf(this);
	}
};

typedef Node* pNode;

class RBTree {
private:
	pNode root;

	void erase_node(pNode x) {
		if (x) {
			x -> prev = x->left = x->right = NULL;
			delete x;
		}
	}

	pNode grandparent(pNode x) {
		if (!x) return NULL;
		if (!x->prev) return NULL;
		return x->prev->prev;
	}

	pNode uncle(pNode x) {
		pNode grand = grandparent(x);
		if (!grand) return NULL;
		if (x->prev == grand->left) return grand->right;
		if (x->prev == grand->right) return grand->left;
	}

	pNode sibling(pNode x) {
		if (!x->prev) return NULL;
		if (x->prev->left == x) return x->prev->right;
		if (x->prev->right == x) return x->prev->left;
	}

	int insert_case1(pNode n) {
		if (n->prev == NULL) 
			n->color = BLACK;
		else
			insert_case2(n);
		return 0;
	}

	int insert_case2(pNode n) {
		if (n->prev->color == BLACK)
			return 0;
		else
			insert_case3(n);
	}

	int insert_case3(pNode n) {
		pNode u = uncle(n), g;
		if ((u != NULL) && (u->color == RED)) {
			n->prev->color = BLACK;
			u->color = BLACK;
			g = grandparent(n);
			g->color = RED;
			insert_case1(g);
		} else
		{
			insert_case4(n);
		}
		return 0;
	}

	int insert_case4(pNode n) {
		pNode g = grandparent(n);
		if ((n == n->prev->right) && (n->prev == g->left)) {
			rotate_left(n->prev);
			n = n->left;
		} else if ((n == n->prev->left) && (n->prev == g->right)) {
			rotate_right(n->prev);
			n = n->right;
		}
		insert_case5(n);
		return 0;
	}

	int insert_case5(pNode n) {
		pNode g = grandparent(n);
		n->prev->color = BLACK;
		g->color = RED;
		if ((n == n->prev->left) && (n->prev == g->left)) {
			rotate_right(g);
		} else
		{
			rotate_left(g);
		}
		return 0;
	}

	int fixup_insert(pNode x) {
		insert_case1(x);
		return 0;
	}

	int rotate_right(pNode a) {
		pNode parent = a->prev;
		pNode b = a->left;
		pNode e = b->right;

		if (parent) {
			if (a == parent->left) {
				parent->left = b;
			} else
			{
				parent->right = b;
			}
		} else
		{
			root = b;
		}
		b->prev = parent;


		a->left = e;
		e->prev = a;

		b->right = a;
		a->prev = b;

		return 0;
	}

	int rotate_left(pNode a) {
		pNode parent = a->prev;
		pNode b = a->right;
		pNode d = b->left;

		if (parent) {
			if (a == parent->left) {
				parent->left = b;
			} else
			{
				parent->right = b;
			}
		} else
		{
			root = b;
		}
		b->prev = parent;

		a->right = d;
		d->prev = a;

		b->left = a;
		a->prev = b;

		return 0;
	}

	int delete_case1(pNode n) {
		if (n->prev != NULL)
			delete_case2(n);
		return 0;
	}

	int delete_case2(pNode n) {
		pNode s = sibling(n);
		if (s->color == RED) {
			n->prev->color = RED;
			s->color = BLACK;
			if (n == n->prev->left) 
				rotate_left(n->prev);
			else
				rotate_right(n->prev);
		}
		delete_case3(n);
		return 0;
	}

	int delete_case3(pNode n) {
		pNode s = sibling(n);
		if ((n->prev->color == BLACK) &&
			(s->color == BLACK) &&
			(s->left->color == BLACK) &&
			(s->right->color == BLACK)) {
				s->color = RED;
				delete_case1(n->prev);
		} else
			delete_case4(n);
		return 0;
	}

	int delete_case4(pNode n) {
		pNode s = sibling(n);
		if ((n->prev->color == RED) &&
			(s->color == BLACK) &&
			(s->left->color == BLACK) &&
			(s->right->color == BLACK)) {
				s->color = RED;
				n->prev->color = BLACK;
		} else
			delete_case5(n);
		return 0;
	}
	
	int delete_case5(pNode n) {
        pNode s = sibling(n);
		if (s->color == BLACK) {
			if ((n == n->prev->left) &&
				(s->right->color == BLACK) &&
				(s->left->color == RED)) {
					s->color = RED;
					s->left->color = BLACK;
					rotate_right(s);
			} else if ((n == n->prev->right) &&
				(s->left->color == BLACK) &&
				(s->right->color == RED)) {
					s->color = RED;
					s->right->color = BLACK;
					rotate_left(s);
			}
        }
        delete_case6(n);
		return 0;
	}

	int delete_case6(pNode n) {
		pNode s = sibling(n);
		s->color = n->prev->color;
		n->prev->color = BLACK;
		if (n == n->prev->left) {
			s->right->color = BLACK;
			rotate_left(n->prev);
		} else {
			s->left->color = BLACK;
			rotate_right(n->prev);
		}
		return 0;
	}

	int replace_node(pNode n, pNode child) {
		child->prev = n->prev;
		pNode parent = n->prev;
		if (parent) {
			if (n == parent->left)
				parent->left = child;
			else
				parent->right = child;
		} else
		{
			root = child;
		}

		return 0;
	}

	int delete_if_one_child(pNode n) {
		pNode child = n->right;
		if (n->right->isLeaf) 
			child = n->left;

		replace_node(n, child);
		if (n->color == BLACK) {
			if (child->color == RED) 
				child->color = BLACK;
			else
				delete_case1(child);
		}
		erase_node(n);
		return 0;
	}

public:
	RBTree() {
		root = new Node();
		root->make_leaf();
	}

	int insert(int value) {
		if (exists(value)) return 0;

		pNode new_node = new Node(value, NULL, NULL, NULL, RED, false);	
		new_node->add_leafs();
		
		if (root->isLeaf) {
			erase_node(root);
			root = new_node;
			fixup_insert(root);
			return 0;
		}
		pNode x = root;
		while (!x->isLeaf) {
			if (value < x->value) 
				x = x->left;
			else
				x = x->right;
		}
		pNode parent = x->prev;
		new_node->prev = parent;
		if (x == parent->left) {
			parent->left = new_node;
			erase_node(x);
			fixup_insert(new_node);
		}
		else
		{
			parent->right = new_node;
			erase_node(x);
			fixup_insert(new_node);
		}
		return 0;
	}

	int del(int value) {
		pNode x = root;
		while (!x->isLeaf) {
			if (value == x->value) break;
			if (value < x->value)
				x = x->left;
			else
				x = x->right;
		}
		if (x->isLeaf) return 0;

		if (x->left->isLeaf || x->right->isLeaf) {
			delete_if_one_child(x);
			return 0;
		}
		pNode most = x->left;
		while (!most->isLeaf) most = most->right;
		most = most->prev;
		swap(most->value, x->value);
		delete_if_one_child(most);
		return 0;
	}

	bool exists(int value) {
		pNode x = root;
		while (!x->isLeaf) {
			if (x->value == value) break;
			if (value < x->value) 
				x = x->left;
			else
				x = x->right;
		}
		return !x->isLeaf;
	}

	bool next(int value, int &ret) {
		if (root == NULL) return false;
		ret = inf;
		pNode x = root;
		while (!x->isLeaf) {
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
		pNode x = root;
		while (!x->isLeaf) {
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

	RBTree tree;

	while (scanf("%s %d\n", buf, &x) != -1) {
		c = buf[0];
		if (c == 'i') { // insert
			tree.insert(x);
			continue;
		}
		if (c == 'd') { // delete
			tree.del(x);
			continue;
		}
		if (c == 'e') { // exists
			printf("%s\n", tree.exists(x) ? "true" : "false");
			continue;
		}
		if (c == 'n') { // next
			if (tree.next(x, res))
				printf("%d\n", res);
			else
				printf("none\n");
			continue;
		}
		if (c == 'p') { // prev
			if (tree.prev(x, res))
				printf("%d\n", res);
			else
				printf("none\n");
			continue;
		}
		if (c == 'q') return 0;

	}

	return 0;
}