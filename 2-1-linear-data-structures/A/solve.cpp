#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstdio>
 
using namespace std;
 
#define task_name "stack1"
 
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
 
class St {
    Vector a;
    int cnt;
public:
    St() {
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
    int pop() {
        assert(cnt > 0);
        int res = a.get(cnt - 1);
        --cnt;
        return res;
    }
};
#include <ctime>
int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	

	clock_t t0 = clock();


	
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
		}
	}

	cout << endl;
	clock_t t1 = clock();
	cout << "time: " << (double)(t1 - t0) / CLOCKS_PER_SEC << endl;


	return 0;
}