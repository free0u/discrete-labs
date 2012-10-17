#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define task_name "sort"

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

vector<int> temp;

void merge(vector<int> &a, vector<int> &temp, int l1, int r1, int l2, int r2) {
	int ind1 = l1;
	int ind2 = l2;
	for (int i = l1; i <= r2; ++i) {
		if (ind1 <= r1 && ind2 <= r2) {
			if (a[ind1] < a[ind2]) {
				temp[i] = a[ind1++];
				continue;
			} else
			{
				temp[i] = a[ind2++];
				continue;
			}
		}
		if (ind1 <= r1) {
			temp[i] = a[ind1++];
			continue;
		}
		if (ind2 <= r2) {
			temp[i] = a[ind2++];
			continue;
		}
	}
	for (int i = l1; i <= r2; ++i) {
		a[i] = temp[i];
	}
}

void merge_sort(vector<int> &a, int l, int r) {
	if (r - l + 1 > 1) {
		int m = (l + r) / 2;
		merge_sort(a, l, m);
		merge_sort(a, m + 1, r);
		merge(a, temp, l, m, m + 1, r);
	}
}

bool is_ordering_arr(vector<int> &a) {
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] < a[i - 1]) return false;
    }
    return true;
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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	temp.resize(a.size());
	merge_sort(a, 0, a.size() - 1);
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}

	return 0;
}