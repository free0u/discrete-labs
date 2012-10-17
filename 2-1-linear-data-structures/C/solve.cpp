
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert>
 
using namespace std;
#define task_name "queue1"
 
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
    int reduce(int l, int r) {
        int cnt = abs(l - r);
        if (cnt < size_arr / 4) {
            size_arr /= 2;
            int *temp = new int[size_arr];
            for (int i = l; i <= r; ++i) {
                temp[i - l] = data[i];
            }
			len = cnt + 1;
            delete[] data;
            data = temp;
            return true;
        }
        return false;
    }
    void rotate(int ind) {
        int *temp = new int[size_arr];
        for (int i = 0; i < len; ++i) {
            temp[i] = data[(i + ind) % len];
        }
        delete[] data;
        data = temp;    
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
  
 
 
class Queue {
    Vector a;
    int start, end;
    int cnt;
public:
    Queue() {
        start = end = cnt = 0;
    }
    void push(int x) {
        if (cnt + 1 < a.size()) {
            end++;
            a.set(end % a.size(), x);
        } else
        {
            a.rotate(start);
            start = 0;
            a.add(x);
            end = a.size() - 1;
        }
        ++cnt;
    }
    int pop() {
        int res = a.get(start);
        start++;
        --cnt;
        if (a.reduce(start, end)) {
            start = 0;
            end = cnt - 1;
        }
        start %= a.size();
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
    scanf("%d\n", &n);
    char c;
     
    for (int i = 0; i < n; ++i) {
        scanf("%c", &c);
        if (c == '+') {
            scanf("%d\n", &x);
            q.push(x);
        } else {
            scanf("\n");
            printf("%d\n", q.pop());
        }
    }
    return 0;
}