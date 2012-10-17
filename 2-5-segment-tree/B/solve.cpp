#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define task_name "rsq"


typedef long long ll;

class RMQ {
	vector<ll> t;
	size_t cnt;
private:
	ll _get_sum(size_t i, size_t tl, size_t tr, size_t l, size_t r) {
		if (tl == l && tr == r) {
			return t[i];
		}
		size_t m = (tl + tr) / 2;
		if (r <= m) { // идем в левый отрезок
			return _get_sum(2 * i, tl, m, l, r);
		}
		if (l >= m + 1) { // идем в правый отрезок
			return _get_sum(2 * i + 1, m + 1, tr, l, r);
		}
		return _get_sum(2 * i, tl, m, l, m) +
			   _get_sum(2 * i + 1, m + 1, tr, m + 1, r);
	}

public:
	void build() {
		cnt = t.size();
		size_t new_size = 1;
		while (new_size < cnt) new_size <<= 1;
		cnt = new_size;

		t.resize(2 * cnt, 0);
		for (size_t i = cnt; i < 2 * cnt; ++i) {
			t[i] = t[i - new_size];
		}

		for (size_t i = cnt - 1; i > 0; --i) {
			t[i] = t[2 * i] + t[2 * i + 1];
		}
	}

	void read_arr(size_t n) {
		t.resize(n);
		for (size_t i = 0; i < n; ++i) {
			scanf("%I64d", &t[i]);
		}
	}

	void set(size_t i, ll value) {
		i += (cnt - 1);

		t[i] = value;

		while (i /= 2) {
			t[i] = t[2 * i] + t[2 * i + 1];
		}
	}

	ll get_sum(size_t l, size_t r) {
		return _get_sum(1, 1, cnt, l, r);
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
	ll x, y;
	while (scanf("%s %I64d %I64d\n", cmd, &x, &y) != EOF) {
		if (cmd[0] == 's' && cmd[1] == 'u') {
			printf("%I64d\n", a.get_sum(x, y));
		}
		if (cmd[0] == 's' && cmd[1] == 'e') {
			a.set(x, y);
		}
		if (cmd[0] == 'q') {
			return 0;
		}
	}

	return 0;
}