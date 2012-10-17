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

#define task_name "netcheck"

class sorting_network {
	int n, k;
	vector<vector<pair<int, int> > > network;
public:
	sorting_network() {}
	sorting_network(int _n, int _k) {
		n = _n;
		k = _k;

		network.resize(k);
	}
	void add_comparator(int k, int i, int j) {
		if (i > j) swap(i, j);
		network[k].push_back(make_pair(i, j));
	}
	void sorting(vector<int> &arr) {
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < network[i].size(); ++j) {
				int a, b;
				a = network[i][j].first;
				b = network[i][j].second;
				if (arr[a] > arr[b]) swap(arr[a], arr[b]);
			}
		}
	}
	void print() {
		int cnt_comp = 0;
		for (int j = 0; j < k; ++j) {
			cnt_comp += network[j].size();
		}
		printf("%d %d %d\n", n, cnt_comp, k);
		for (int i = 0; i < k; ++i) {
			printf("%d ", network[i].size());
			for (int j = 0; j < network[i].size(); ++j) {
				printf("%d %d ", network[i][j].first + 1, network[i][j].second + 1);
			}
			printf("\n");
		}
	}
	int get_size() {
		return n;
	}
};


bool is_ordering_arr(vector<int> &a) {
	for (int i = 1; i < a.size(); ++i) {
		if (a[i] < a[i - 1]) return false;
	}
	return true;
}

bool next_binary_perm(vector<int> &a) {
	for (int i = a.size() - 1; i >= 0; --i) {
		if (a[i] == 0) {
			a[i] = 1;
			for (int j = i + 1; j < a.size(); ++j) {
				a[j] = 0;
			}
			return true;
		}
	}
	return false;
}

bool test_network(sorting_network &net) {
	int n = net.get_size();
	vector<int> a(n);
	do {
		vector<int> b(a);
		net.sorting(b);
		if (!is_ordering_arr(b)) return false;
	} while (next_binary_perm(a));
	return true;
}


int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output_true.txt", "w", stdout);
#endif
	
	int n, m, k;
	cin >> n >> m >> k;

	sorting_network net(n, k);
	
	int r, x, y;
	for (int i = 0; i < k; ++i) {
		scanf("%d", &r);
		for (int j = 0; j < r; ++j) {
			scanf("%d %d", &x, &y);
			net.add_comparator(i, x - 1, y - 1);
		}
	}

	printf("%s\n", test_network(net) ? "Yes" : "No");
	return 0;
}