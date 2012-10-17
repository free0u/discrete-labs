#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repa(i, a, b) for (int i = (a); i <= (b); ++i)
#define sqr(x) ((x)*(x))
#define all(c) c.begin(), c.end()
#define re return

#define task_name "rmq"

const int inf = 1e9 + 31;

class RMQ {
	vector<int> t;
	size_t cnt;
private:
	int _get_min(size_t i, size_t tl, size_t tr, size_t l, size_t r) {
		if (tl == l && tr == r) {
			return t[i];
		}
		size_t m = (tl + tr) / 2;
		if (r <= m) { // идем в левый отрезок
			return _get_min(2 * i, tl, m, l, r);
		}
		if (l >= m + 1) { // идем в правый отрезок
			return _get_min(2 * i + 1, m + 1, tr, l, r);
		}
		return min(_get_min(2 * i, tl, m, l, m),
			   _get_min(2 * i + 1, m + 1, tr, m + 1, r));

	}

public:
	void build() {
		cnt = t.size();
		size_t new_size = 1;
		while (new_size < cnt) new_size <<= 1;
		cnt = new_size;

		t.resize(2 * cnt, inf);
		for (size_t i = cnt; i < 2 * cnt; ++i) {
			t[i] = t[i - new_size];
		}

		for (size_t i = cnt - 1; i > 0; --i) {
			t[i] = min(t[2 * i], t[2 * i + 1]);
		}
	}

	void read_arr(size_t n) {
		t.resize(n);
		for (size_t i = 0; i < n; ++i) {
			scanf("%d", &t[i]);
		}
	}

	void set(size_t i, int value) {
		i += (cnt - 1);

		t[i] = value;

		while (i /= 2) {
			t[i] = min(t[2 * i], t[2 * i + 1]);
		}
	}

	int get_min(size_t l, size_t r) {
		int t = _get_min(1, 1, cnt, l, r);
		return t;
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
	
	size_t n;
	cin >> n;
	
	RMQ a;
	a.read_arr(n);
	a.build();
	char cmd[5];
	int x, y;
	while (scanf("%s %d %d\n", cmd, &x, &y) != EOF) {
		if (cmd[0] == 'm') {
			printf("%d\n", a.get_min(x, y));
		}
		if (cmd[0] == 's') {
			a.set(x, y);
		}
		if (cmd[0] == 'q') {
			return 0;
		}
	}

	return 0;
}