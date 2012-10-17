
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert>
 
using namespace std;
#define task_name "queuemin"
 
template<class T> class Vector {
    int len, size_arr;
    T *data;
public:
    Vector() {
        len = 0;
        data = new T[1];
        size_arr = 1;
    }
    void ensure_capacity(int capacity) {
        if (capacity > size_arr) {
            size_arr *= 2;
            T *temp = new T[size_arr];
            for (int i = 0; i < len; ++i) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            ensure_capacity(capacity);
        }
    }
    int reduce(int l, int r) {
        int cnt = abs(l - r);
        if (cnt < size_arr / 4) {
            size_arr /= 2;
            len = cnt + 1;
            T *temp = new T[size_arr];
            for (int i = l; i <= r; ++i) {
                temp[i - l] = data[i];
            }
            delete[] data;
            data = temp;
            return true;
        }
        return false;
    }
 
    void add(T x) {
        ensure_capacity(len + 1);
        data[len++] = x;
    }
    T get(int i) {
        assert(i >= 0 && i < len);
        return data[i];
    }
	T operator[] (int i) {
		return get(i);
	}
    void set(int i, T x) {
        assert(i >= 0 && i < len);
        data[i] = x;
    }
    int size() {
        return len;
    }
	void mysort() {
		sort(data, data + len);
	}
    void dump() {
        for (int i = 0; i < len; ++i) {
                cout << data[i] << " ";
        }
    }
};
  
 
 
//class Queue {
//    Vector<int> a;
//    int start, end;
//    int cnt;
//public:
//    Queue() {
//        start = end = cnt = 0;
//    }
//    void push(int x) {
//        if (end + 1 < a.size()) {
//            a.set(end + 1, x);
//        } else
//        {
//            a.add(x);
//        }
//        ++end;
//        ++cnt;
//    }
//    int pop() {
//        int res = a.get(start);
//        start++;
//        --cnt;
//        if (a.reduce(start, end)) {
//            start = 0;
//            end = cnt - 1;
//        }
//        return res;
//    }
//};
 

struct Node {
	int x, y;
	Node() {}
	Node(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

class St {
    Vector<Node> a;
    int cnt;
public:
    St() {
        cnt = 0;
    }
	bool is_empty() {
		return cnt == 0;
	}
    void push(int x) {
        if (cnt + 1 <= a.size()) {
			a.set(cnt, Node(x, is_empty() ? x : min(x, peek().y)));
        } else {
            a.add(Node(x, is_empty() ? x : min(x, peek().y)));
        }
        ++cnt;
    }
	Node peek() {
        assert(cnt > 0);
        Node res = a.get(cnt - 1);
        return res;
    }
    Node pop() {
        assert(cnt > 0);
        Node res = a.get(cnt - 1);
        --cnt;
        return res;
    }
};

class Queue {
    St s1, s2;
public:
    Queue() {
    }
    void push(int x) {
        s1.push(x);
    }
    int pop() {
		if (!s2.is_empty()) {
			return s2.pop().x;
		}
		while (!s1.is_empty()) {
			s2.push(s1.pop().x);
		}
		return s2.pop().x;
    }
	int extract_min() {
		int a = (s1.is_empty() ? 1e9 : s1.peek().y);
		int b = (s2.is_empty() ? 1e9 : s2.peek().y);
		return min(a, b);
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
    scanf("%d\n", &n);
    char c;
     
    for (int i = 0; i < n; ++i) {
        scanf("%c", &c);
        if (c == '+') {
            scanf("%d\n", &x);
            q.push(x);
        } else if (c == '?') {
            scanf("\n");
            printf("%d\n", q.extract_min());
        } else
		{
			scanf("\n");
            //printf("%d\n", q.pop());
			q.pop();
		}
    }
    return 0;
}