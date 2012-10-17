#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

#define task_name "postfix"

class Vector {
    int len, size_arr;
    int *data;
public:
    Vector() {
        len = 0;
        data = new int[1];
        size_arr = 1;
    }
    void ensure_capacity(int capacity) {
        if (capacity > size_arr) {
            size_arr *= 2;
            int *temp = new int[size_arr];
            for (int i = 0; i < len; ++i) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            ensure_capacity(capacity);
        }
    }
    void add(int x) {
        ensure_capacity(len + 1);
        data[len++] = x;
    }
    int get(int i) {
        assert(i >= 0 && i < len);
        return data[i];
    }
    void set(int i, int x) {
        assert(i >= 0 && i < len);
        data[i] = x;
    }
    int size() {
        return len;
    }
    void dump() {
        for (int i = 0; i < len; ++i) {
            cout << data[i] << " ";
        }
    }
};
 
class Stack {
    Vector a;
    int cnt;
public:
    Stack() {
        cnt = 0;
    }
    void push(int x) {
        if (cnt + 1 <= a.size()) {
            a.set(cnt, x);
        } else {
            a.add(x);
        }
        ++cnt;
    }
	int peek() {
		assert(cnt > 0);
        return a.get(cnt - 1);
	}
    int pop() {
        assert(cnt > 0);
        int res = a.get(cnt - 1);
        --cnt;
        return res;
    }
	bool is_empty() {
		return cnt == 0;
	}
	int size() {
		return cnt;
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
	
	Stack st;

	char c;
	int a, b;
	while (scanf("%c", &c) != -1) {
		if (c == ' ') continue;
		if (c >= '0' && c <= '9') {
			st.push(c - '0');
			continue;
		}
		if (st.is_empty()) {
			continue;
		}
		if (st.size() == 1) {
			break;
		}

		b = st.pop();
		a = st.pop();
		if (c == '+') {
			st.push(a + b);
			continue;
		}
		if (c == '-') {
			st.push(a - b);
			continue;
		}
		if (c == '*') {
			st.push(a * b);
			continue;
		}

	}
	cout << st.pop();

	return 0;
}