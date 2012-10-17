#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "priorityqueue"

const int inf = 1e9 + 31;

class Heap {
	vector<int> data, 
		cmd_ind, // cmd_ind[i] - индекс элемента, который добавлен i-ой командой
		cmd_num; // cmd_num[i] - номер команды, при которой добавлен i-ый элемент в куче
	int cnt_cmd; // счетчик команд
	int n; // кол-во элементов в куче
public:
	Heap() {
		cnt_cmd = -1;
		n = 0;
	}
	void set(vector<int> &a, int i, int value) {
		if (i < a.size()) 
			a[i] = value;
		else {
			a.resize(i + 1);
			a[i] = value;
		}
	}

	void sift_up(int i) {
		int par = (i - 1) / 2;
		if (data[i] < data[par]) {
			swap(data[i], data[par]);
			int s1 = cmd_num[i], s2 = cmd_num[par];
			swap(cmd_num[i], cmd_num[par]);
			swap(cmd_ind[s1], cmd_ind[s2]);
			sift_up(par);
		}
	}

	void sift_down(int i) {
		int l, r, m;
		l = 2 * i + 1;
		r = l + 1;
		if (l < n && data[l] < data[i])
			m = l;
		else
			m = i;
		if (r < n && data[r] < data[m])
			m = r;
		if (m != i) {
			int par = m;
			swap(data[i], data[par]);
			int s1 = cmd_num[i], s2 = cmd_num[par];
			swap(cmd_num[i], cmd_num[par]);
			swap(cmd_ind[s1], cmd_ind[s2]);
			sift_down(m);
		}
	}

	void push(int x) {
		++cnt_cmd;
		//data.push_back(x);
		set(data, n, x);
		++n;
		set(cmd_ind, cnt_cmd, n - 1);
		set(cmd_num, n - 1, cnt_cmd);
		sift_up(n - 1);
	}

	int get_min() {
		++cnt_cmd;
		if (n == 0) {
			return inf;
		}
		int res = data[0];
		data[0] = data[n - 1];
		
		int i = 0;
		int par = n - 1;
		swap(data[i], data[par]);
		int s1 = cmd_num[i], s2 = cmd_num[par];
		swap(cmd_num[i], cmd_num[par]);
		swap(cmd_ind[s1], cmd_ind[s2]);
		
		n--;
		sift_down(0);
		return res;
	}

	void change(int pos, int value) {
		++cnt_cmd;
		pos = cmd_ind[pos];
		data[pos] = value;
		sift_up(pos);
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
	
	Heap h;
	char cmd[15];
	int x, y;
	while(scanf("%s", cmd) != -1) {
		if (cmd[0] == 'p') {
			scanf("%d\n", &x);
			h.push(x);
			continue;
		}
		if (cmd[0] == 'e') {
			scanf("\n");
			int t = h.get_min();
			if (t == inf)
				printf("*\n");
			else
				printf("%d\n", t);
			continue;
		}
		if (cmd[0] == 'd') {
			scanf("%d %d\n", &x, &y);
			h.change(x - 1, y);
			continue;
		}
		if (cmd[0] == 'q') break;
	}

	return 0;
}