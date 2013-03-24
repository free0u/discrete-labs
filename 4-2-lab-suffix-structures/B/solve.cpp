#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "array"

vector<int> suffix_array(string const& str) {
	int n = str.length();
	vector<int> sa(n);
	vector<int> rank(n);
	int max_len = n;
	for (int i = 0; i < n; ++i) {
		rank[i] = str[i];
		max_len = max(max_len, str[i] + 1);
	}
	vector<int> cnt(max_len);
	for (int i = 0; i < n; ++i) {
		++cnt[rank[i]];
	}
	for (int i = 1; i < cnt.size(); ++i) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = 0; i < n; i++) {
		sa[--cnt[rank[i]]] = i;
	}
	for (int len = 1; len < n; len *= 2) {
		vector<int> r(rank);
		rank[sa[0]] = 0;
		for (int i = 1; i < n; ++i) {
			int s1 = sa[i - 1];
			int s2 = sa[i];
			if (r[s1] == r[s2] && max(s1, s2) + len < n && r[s1 + len / 2] == r[s2 + len / 2]) {
				rank[s2] = rank[s1];
			} else
			{
				rank[s2] = i;
			}
		}
		for (int i = 0; i < n; ++i) {
			cnt[i] = i;
		}
		vector<int> s(sa);
		for (int i = 0; i < n; ++i) {
			int s1 = s[i] - len;
			if (s1 >= 0) {
				sa[cnt[rank[s1]]++] = s1;
			}
		}
	}
	return sa;
}


vector<int> lcp(vector<int> &sa, string const& s) {
	int n = sa.size();
	vector<int> rank(n);
	for (int i = 0; i < n; ++i) {
		rank[sa[i]] = i;
	}
	vector<int> lcp(n - 1);
	for (int i = 0, h = 0; i < n; ++i) {
		if (rank[i] < n - 1) {
			int j = sa[rank[i] + 1];
			while (max(i, j) + h < s.length() && s[i + h] == s[j + h]) {
				++h;
			}
			lcp[rank[i]] = h;
			if (h > 0) {
				--h;
			}
		}
	}
	return lcp;
}

int main() {
#ifndef HOME_free0u
	freopen(task_name".in", "r", stdin);
	freopen(task_name".out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	string s;
	cin >> s;

	vector<int> a = suffix_array(s);
	for (int i = 0; i < a.size(); ++i) {
		printf("%d ", a[i] + 1);
	}


	return 0;
}