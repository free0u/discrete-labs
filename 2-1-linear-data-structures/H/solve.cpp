#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <sstream>
#include <algorithm>
 
using namespace std;
#define task_name "quack"
 
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
	int qsort(int l = -1, int r = -1) {
		if (l == -1) {
			l = 0;
			r = len - 1;
		}
		int n = r - l + 1;
		if (n <= 1)
			return 0;
		T x = data[(n - 1) / 2];
		int i = 0;
		int j = n - 1;
		while (true) {
			while (data[i] < x) i++;
			while (data[j] > x) j--;
			if (i <= j) {
				if (i < j) {
					T tmp = data[i];
					data[i] = data[j];
					data[j] = tmp;
				}
				i++;
				j--;
			} else {
				break;
			}
		}
		qsort(0, j + 1);
		qsort(i, n - i);
		return 0;
	}
    void dump() {
        for (int i = 0; i < len; ++i) {
                cout << data[i] << " ";
        }
    }
};

class Queue {
    Vector<int> a;
    int start, end;
    int cnt;
public:
    Queue() {
        start = end = cnt = 0;
    }
    void push(int x) {
        if (end + 1 < a.size()) {
            a.set(end + 1, x);
        } else
        {
            a.add(x);
        }
        ++end;
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
        return res;
    }
};

inline int mod(long long int a) {
		return (a) % 65536;
}

struct Label {
	string name;
	int pos;
	Label() {}
	Label(string _name, int _pos) {
		name = _name;
		pos = _pos;
	}
	bool operator < (const Label &a) const {
		return name < a.name;
	}
	bool operator > (const Label &a) const {
		return name > a.name;
	}
};


Vector<Label> labels;
int find_pos(string &s) {
	int l = 0;
	int r = labels.size() - 1;
	int m;
	while (l < r) {
		m = (l + r) / 2;
		if (labels[m].name < s) 
			l = m + 1;
		else
			r = m;
	}
	return labels[l].pos;

	//return -1;
	//int res = -1;
	//for (int i = 0; i < labels.size(); ++i) {
	//	if (labels[i].name == s) res = labels[i].pos;
	//}
	//return res;
}

int parse_int(string s) {
	stringstream ss(s);
	int res;
	ss >> res;
	return res;
}

int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
	Queue q;
	int reg[26];


	Vector<string> cmds;
	string temp;
	int pos = 0;
	while (getline(cin, temp)) { 
		cmds.add(temp);
		if (temp[0] == ':') {
			labels.add(Label(temp.substr(1, temp.size() - 1), pos));
		}
		++pos;
	}
	labels.mysort();
	long long int x, y;
	string cmd;
	pos = 0;
	while (true) {
		if (pos == cmds.size()) break;
		cmd = cmds[pos];
		char c = cmd[0];
		if (c == '+') {
			x = q.pop();
			y = q.pop();
			q.push(mod(x + y));
			++pos;
			continue;
		}
		if (c == '-') {
			x = q.pop();
			y = q.pop();
			q.push(mod(x - y + 65536));
			++pos;
			continue;
		}
		if (c == '*') {
			x = q.pop();
			y = q.pop();
			q.push(mod(x * y));
			++pos;
			continue;
		}
		if (c == '/') {
			x = q.pop();
			y = q.pop();
			if (y == 0) 
				q.push(0);
			else
				q.push(mod(x / y));
			++pos;
			continue;
		}
		if (c == '%') {
			x = q.pop();
			y = q.pop();
			if (y == 0) 
				q.push(0);
			else
				q.push(mod(x % y));
			++pos;
			continue;
		}
		if (c == '>') {
			int r = cmd[1] - 'a';
			reg[r] = q.pop();
			++pos;
			continue;
		}
		if (c == '<') {
			int r = cmd[1] - 'a';
			q.push(reg[r]);
			++pos;
			continue;
		}
		if (c == 'P' && cmd.size() == 1) {
			printf("%d\n", q.pop());
			++pos;
			continue;
		}
		if (c == 'P') {
			int r = cmd[1] - 'a';
			printf("%d\n", reg[r]);
			++pos;
			continue;
		}
		if (c == 'C' && cmd.size() == 1) {
			printf("%c", (char)(q.pop() % 256));
			++pos;
			continue;
		}
		if (c == 'C') {
			int r = cmd[1] - 'a';
			printf("%c", (char)(reg[r] % 256));
			++pos;
			continue;
		}
		if (c == ':') {
			++pos;
			continue;
		}
		if (c == 'J') {
			pos = find_pos(cmd.substr(1, cmd.size() - 1));
			continue;
		}
		if (c == 'Z') {
			int r = cmd[1] - 'a';
			if (reg[r] == 0) {
				pos = find_pos(cmd.substr(2, cmd.size() - 2));
				continue;
			}
			++pos;
			continue;
		}
		if (c == 'E') {
			int r1 = cmd[1] - 'a', r2 = cmd[2] - 'a';
			if (reg[r1] == reg[r2]) {
				pos = find_pos(cmd.substr(3, cmd.size() - 3));
				continue;
			}
			++pos;
			continue;
		}
		if (c == 'G') {
			int r1 = cmd[1] - 'a', r2 = cmd[2] - 'a';
			if (reg[r1] > reg[r2]) {
				pos = find_pos(cmd.substr(3, cmd.size() - 3));
				continue;
			}
			++pos;
			continue;
		}
		if (c == 'Q') {
			break;
		}
		q.push(parse_int(cmd));
		++pos;
	}

    return 0;
}