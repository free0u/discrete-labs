#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


#define task_name "kth"

void quick_sort(vector<int> &a, int l, int r) {
	int i, j, mid;
	i = l;
	j = r;
	mid = i + (rand() % (j - i + 1));
	int x = a[mid];
	do {
		while (a[i] < x) ++i;
		while (a[j] > x) --j;
		if (i <= j) {
			swap(a[i], a[j]);
			++i;
			--j;
		}
	} while (i <= j);
	if (l < j) quick_sort(a, l, j);
	if (i < r) quick_sort(a, i, r);
}

int nth(vector<int> &a, int k) {
	for (int l = 0, r = a.size() - 1; ; ) {
		if (r <= l + 1) {
			if (r == l + 1 && a[r] < a[l]) {
				swap(a[l], a[r]);
			}
			return a[k];
		}

		int mid = (l + r) / 2;
		swap(a[mid], a[l + 1]);
		if (a[l] > a[r]) {
			swap(a[l], a[r]);
		}
		if (a[l + 1] > a[r]) {
			swap(a[l + 1], a[r]);
		}
		if (a[l] > a[l + 1]) {
			swap(a[l], a[l + 1]);
		}

		int	i = l + 1;
		int j = r;
		int cur = a[l + 1];
		while (true) {
			while (a[++i] < cur);
			while (a[--j] > cur);
			if (i > j) break;
			swap (a[i], a[j]);
		}

		a[l + 1] = a[j];
		a[j] = cur;

		if (j >= k)
			r = j - 1;
		if (j <= k)
			l = i;
	}
}

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	int A, B, C, a1, a2;
	cin >> A >> B >> C >> a1 >> a2;

	if (n == 1) {
		cout << a1 << endl;
		return 0;
	}

	vector<int> a;
	a.push_back(a1);
	a.push_back(a2);

	for (int i = 2; i < n; ++i) {
		a.push_back(A * a[i - 2] + B * a[i - 1] + C);
	}


	cout << nth(a, k - 1);
	return 0;

	quick_sort(a, 0, a.size() - 1);

	cout << a[k - 1];
	return 0;

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		++cnt;
		if (cnt == k) {
			cout << a[i] << endl;
			return 0;
		}
		while (i + 1 < n && a[i] == a[i + 1]) ++i;
	}
	return 0;
}