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

#define task_name "crypto"

const int inf = 1e9 + 31;

int mod;

struct matrix {
	int a, b, c, d;
	matrix() {}
	void read() {
		scanf("%d%d%d%d", &a, &b, &c, &d); 
	}
	void print() {
		a %= mod;
		b %= mod;
		c %= mod;
		d %= mod;
		printf("%d %d\n%d %d\n", a, b, c, d);
	}
	matrix& mul(matrix &m) {
		int na, nb, nc, nd;
		na = a * m.a + b * m.c;
		nb = a * m.b + b * m.d;
		nc = c * m.a + d * m.c;
		nd = c * m.b + d * m.d;
		a = na % mod;
		b = nb % mod;
		c = nc % mod;
		d = nd % mod;
		return *this;
	}
	matrix operator*(matrix &m) {
		matrix n;
		n = *this;
		return n.mul(m);
	}
};

class RMQ {
	vector<matrix> t;
	size_t cnt;
	matrix one;
private:
	matrix _get_mul(size_t i, size_t tl, size_t tr, size_t l, size_t r) {
		if (tl == l && tr == r) {
			return t[i];
		}
		size_t m = (tl + tr) / 2;
		if (r <= m) { // идем в левый отрезок
			return _get_mul(2 * i, tl, m, l, r);
		}
		if (l >= m + 1) { // идем в правый отрезок
			return _get_mul(2 * i + 1, m + 1, tr, l, r);
		}
		matrix m1, m2;
		m1 = _get_mul(2 * i, tl, m, l, m);
		m2 = _get_mul(2 * i + 1, m + 1, tr, m + 1, r);
		return m1 * m2;
	}

public:
	RMQ() {
		one.a = 1;
		one.b = 0;
		one.c = 0;
		one.d = 1;
	}
	void build() {
		cnt = t.size();
		size_t new_size = 1;
		while (new_size < cnt) new_size <<= 1;
		cnt = new_size;

		t.resize(2 * cnt, one);
		for (size_t i = cnt; i < 2 * cnt; ++i) {
			t[i] = t[i - new_size];
		}

		for (size_t i = cnt - 1; i > 0; --i) {
			//t[i] = min(t[2 * i], t[2 * i + 1]);
			t[i] = t[2 * i] * t[2 * i + 1];
		}
	}

	void read_arr(size_t n) {
		t.resize(n);
		for (size_t i = 0; i < n; ++i) {
			//scanf("%d", &t[i]);
			t[i].read();
		}
	}

	matrix get_mul(size_t l, size_t r) {
		matrix t = _get_mul(1, 1, cnt, l, r);
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
	
	size_t n, m;
	cin >> mod >> n >> m;
	
	RMQ a;
	a.read_arr(n);
	a.build();
	
	int x, y;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		a.get_mul(x, y).print();
		printf("\n");
	}

	return 0;
}