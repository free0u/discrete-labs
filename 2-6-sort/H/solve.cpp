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

#define task_name "netbuild"

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
	void copy(int i, int j) {
		network[i].assign(network[j].begin(), network[j].end());
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

double my_log(double base, double value) {
	double res = log(value);
	return res / log(base);
}

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;

	if (n == 1) {
		printf("1 0 0\n");
		return 0;
	}

	int cnt_in = 1;
	while (cnt_in < n) cnt_in <<= 1;

	int k = my_log(2.0, (double)cnt_in);


	// http://upload.wikimedia.org/wikipedia/en/thumb/c/c6/BitonicSort.svg/843px-BitonicSort.svg.png

	vector<vector<pair<int, int> > > temp(k);
	vector<vector<pair<int, int> > > temp2(k);
	int cnt_block =	cnt_in / 2;
	for (int layer = 0; layer < k; ++layer, cnt_block /= 2) {
		int cnt_in_block = cnt_in / cnt_block;
		int cnt_comp_in_block = cnt_in_block / 2;
		for (int block = 0; block < cnt_block; ++block) {
			for (int comp = 0; comp < cnt_comp_in_block; ++comp) {
				int ind1 = block * cnt_in_block + comp;
				int ind2 = ind1 + cnt_comp_in_block;
				temp[layer].push_back(make_pair(ind1, ind2));
				ind2 = (block + 1) * cnt_in_block - (comp + 1);
				temp2[layer].push_back(make_pair(ind1, ind2));
			}
		}
	}


	int new_k = (k + 1) * k;
	new_k /= 2;

	sorting_network net(n, new_k);

	int pos = 0;
	for (int layer = 0; layer < k; ++layer) {
		for (int i = 0; i < temp2[layer].size(); ++i) {
			if (temp2[layer][i].second < n)
				net.add_comparator(pos, temp2[layer][i].first, temp2[layer][i].second);
		}
		++pos;
		for (int i = layer - 1; i >= 0; --i) {
				for (int j = 0; j < temp2[layer].size(); ++j) {
				if (temp[i][j].second < n)
					net.add_comparator(pos, temp[i][j].first, temp[i][j].second);
			}
			++pos;
		}
	}

	

	net.print();
	return 0;
}