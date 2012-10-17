#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cstdio>
 
using namespace std;
 
#define task_name "stack2"
 

double sum;
clock_t t0, t1;

struct Node {
	int data;
	Node *next;
	Node(Node *n, int d) {
		next = n;
		data = d;
	}
};
 
struct St {
	Node *head;
	void push(int x) {
		Node *temp = new Node(head, x);
		head = temp;
	}
	int pop() {
		int res = head->data;
		Node *temp = head;
		head = head->next;
		delete temp;
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
	
	//Node* ptr;
	//for (int i = 0; i < 1; ++i) {
	//	Node t(0, 12);
	//	ptr = &t;
	//	cout << ptr->data << endl;
	//}


	//cout << ptr->data;
	//return 0;


	
	//sum = 0;

	//for (int i = 0; i < 1e6 / 2; ++i) {
	//	Node *temp = new Node(temp, 1);
	//	cout << temp->data << endl;
	//	temp->data = rand();
	//	Node *t = temp;
	//	temp = temp->next;

	//	t0 = clock();
	//	delete t;
	//	t1 = clock();
	//	sum = sum + t1 - t0;
	//}


	//t1 = clock();
	//cout << "time: " << (double)(sum) / CLOCKS_PER_SEC << endl;
	//return 0;


	//int tt = 1e6;
	//cout << tt << endl;
	//for (int i = 0; i < tt; ++i) {
	//	cout << "+ " << rand();
	//	cout << endl;
	//	cout << "- ";
	//	cout << endl;
	//}
	////for (int i = 0; i < tt / 2; ++i) {
	////	cout << "- ";
	////	cout << endl;
	////}


	//return 0;

	t0 = clock();
	St st;
 
	int n, x;
	scanf("%d\n", &n);
	char c;
	
	for (int i = 0; i < n; ++i) {
		scanf("%c", &c);
		if (c == '+') {
			scanf("%d\n", &x);
			st.push(x);
		} else {
			scanf("\n");
			printf("%d\n", st.pop());
			//cout << st.pop() << endl;
		}
	}

	t1 = clock();
	cout << "time: " << (double)(t1 - t0) / CLOCKS_PER_SEC << endl;

	return 0;
}