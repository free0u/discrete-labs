#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;


#define task_name "rmq2"

const ll inf = 1e18 + 31;

class RMQ {
	vector<ll> t;
	vector<ll> d_add;
	vector<bool> equal;
	size_t cnt;
	
private:
	ll _get_min(size_t i, size_t tl, size_t tr, size_t l, size_t r) {
		if (tl == l && tr == r) {
			return t[i] + d_add[i];
		}
		size_t m = (tl + tr) / 2;
		push(i);
		ll ans;
		if (r <= m) { // идем в левый отрезок
			ans = _get_min(2 * i, tl, m, l, r);
			t[i] = min(t[2 * i] + d_add[2 * i], t[2 * i + 1] + d_add[2 * i + 1]);
			return ans;
		}
		if (l >= m + 1) { // идем в правый отрезок
			ans = _get_min(2 * i + 1, m + 1, tr, l, r);
			t[i] = min(t[2 * i] + d_add[2 * i], t[2 * i + 1] + d_add[2 * i + 1]);
			return ans;
		}

		ll m1, m2;
		m1 = _get_min(2 * i, tl, m, l, m);
		m2 = _get_min(2 * i + 1, m + 1, tr, m + 1, r);
		t[i] = min(t[2 * i] + d_add[2 * i], t[2 * i + 1] + d_add[2 * i + 1]);
		return min(m1, m2);

	}
	void push(size_t i) {
		if (i < cnt) {
			if (equal[i]) {
				equal[i] = false;
				equal[2 * i] = equal[2 * i + 1] = true;
				
				t[2 * i] = t[i] + d_add[i];
				t[2 * i + 1] = t[i] + d_add[i];

				d_add[i] = 0;
				d_add[2 * i] = 0;
				d_add[2 * i + 1] = 0;
			} else
			{
				d_add[2 * i] += d_add[i];
				d_add[2 * i + 1] += d_add[i];
				d_add[i] = 0;
			}
		}
	}

	ll _add(size_t i, size_t tl, size_t tr, size_t l, size_t r, ll add) {
		if (tl == l && tr == r) {
			d_add[i] += add;
			return 0;
		}
		size_t m = (tl + tr) / 2;
		push(i);
		if (r <= m) { // идем в левый отрезок
			_add(2 * i, tl, m, l, r, add);
			t[i] = min(t[2 * i] + d_add[2 * i], t[2 * i + 1] + d_add[2 * i + 1]);
			return 0;
		}
		if (l >= m + 1) { // идем в правый отрезок
			_add(2 * i + 1, m + 1, tr, l, r, add);
			t[i] = min(t[2 * i] + d_add[2 * i], t[2 * i + 1] + d_add[2 * i + 1]);

			return 0;
		}


		_add(2 * i, tl, m, l, m, add);
		_add(2 * i + 1, m + 1, tr, m + 1, r, add);
		t[i] = min(t[2 * i] + d_add[2 * i], t[2 * i + 1] + d_add[2 * i + 1]);

		return 0;
	}


	
	ll _set(size_t i, size_t tl, size_t tr, size_t l, size_t r, ll value) {
		if (tl == l && tr == r) {
			t[i] = value;
			equal[i] = true;
			d_add[i] = 0;
			return 0;
		}

		size_t m = (tl + tr) / 2;
		push(i);
		if (r <= m) { // идем в левый отрезок
			_set(2 * i, tl, m, l, r, value);
			t[i] = min(t[2 * i] + d_add[2 * i], t[2 * i + 1] + d_add[2 * i + 1]);
			return 0;
		}
		if (l >= m + 1) { // идем в правый отрезок
			_set(2 * i + 1, m + 1, tr, l, r, value);
			t[i] = min(t[2 * i] + d_add[2 * i], t[2 * i + 1] + d_add[2 * i + 1]);

			return 0;
		}


		_set(2 * i, tl, m, l, m, value);
		_set(2 * i + 1, m + 1, tr, m + 1, r, value);
		t[i] = min(t[2 * i] + d_add[2 * i], t[2 * i + 1] + d_add[2 * i + 1]);

		return 0;
	}

	 
public:
	void build() {
		cnt = t.size();
		size_t new_size = 1;
		while (new_size < cnt) new_size <<= 1;
		cnt = new_size;

		t.resize(2 * cnt, inf);
		d_add.resize(2 * cnt, 0);
		equal.resize(2 * cnt, 0);
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
			scanf("%I64d", &t[i]);
		}
	}

	void add(size_t l, size_t r, ll value) {
		_add(1, 1, cnt, l, r, value);
	}

	void set(size_t l, size_t r, ll value) {
		_set(1, 1, cnt, l, r, value);
	}

	ll get_min(size_t l, size_t r) {
		ll t = _get_min(1, 1, cnt, l, r);
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
	ll z;
	while (scanf("%s %d %d\n", cmd, &x, &y) != EOF) {
		if (cmd[0] == 'm') {
			printf("%I64d\n", a.get_min(x, y));
		}
		if (cmd[0] == 's') {
			scanf("%I64d", &z);
			a.set(x, y, z);
		}
		if (cmd[0] == 'a') {
			scanf("%I64d", &z);
			a.add(x, y, z);
		}
		if (cmd[0] == 'q') {
			return 0;
		}
	}

	return 0;
}