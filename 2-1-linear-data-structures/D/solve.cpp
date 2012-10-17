#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#define task_name "queue2"
struct Node {
	int data;
	Node *next;
	Node(Node* _next, int _data) {
		data = _data;
		next = _next;
	}
};


class Queue {
	Node *start, *end;
public:
	Queue() {
		start = end = new Node(0, 0);
	}
	void push(int x) {
		end->next = new Node(NULL, x);
		end = end->next;
	}
	int pop() {
		int res = start->next->data;
		start = start->next;
		return res;
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
	
	Queue q;

	int n, x;
	char c;
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%c", &c);
		if (c == '+') {
			scanf("%d\n", &x);
			q.push(x);
		} else
		{
			scanf("\n");
			printf("%d\n", q.pop());
		}
	}


	return 0;
}