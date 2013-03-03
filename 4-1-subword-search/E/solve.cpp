#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "search3"

vector<int> z_function(string const& s) {
	int len = s.length();
	vector<int> res(len);
	int l, r;
	l = r = 0;
	for (int i = 1; i < len; ++i) {
		if (i <= r) {
			res[i] = min(r - i + 1, res[i - l]);
		}
		while (i + res[i] < len && s[res[i]] == s[i + res[i]]) {
			++res[i];
		}
		if (i + res[i] - 1 > r) {
			l = i;
			r = i + res[i] - 1;
		}
	}
	return res;
}

string reverse(string s) {
	reverse(s.begin(), s.end());
	return s;
}

template<typename T>
void out(vector<T> const& a) {
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << " ";
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
	
	string p, t;
	cin >> p >> t;

	string s1 = p + '#' + t;
	string s2 = reverse(p) + '#' + reverse(t);
	

	//cout << s1 << endl << s2 << endl;


	vector<int> z1 = z_function(s1);
	vector<int> z2 = z_function(s2);

	vector<int> ans;
	for (int i = p.length() + 1; i < s1.length(); ++i) {
		//for (int j = 0; j < p.length(); ++j) {
		//	cout << s1[i + j];
		//}
		//cout << " ";
		for (int j = 0; j < z1[i]; ++j) {
			//cout << s1[i + j];
		}
		//cout << " ";
		
		int end_ind = i - 2;
		if (end_ind >= t.length()) break;
		int inv_ind = t.length() - end_ind + p.length();
		
		//cout << " " << end_ind << " " << inv_ind;
		//cout << endl;

		if (inv_ind >= 0) {
			int len = p.length() - z1[i] - 1;
			//cout << len << " " << z2[inv_ind];

			//cout << " " << i - p.length() << " " << (z2[inv_ind] >= len);
			if (z2[inv_ind] >= len) {
				ans.push_back(i - p.length());
			}	
		}
		//cout << endl;
	}


	//cout << endl;
	//out(z1);
	//cout << endl;
	//out(z2);

	//cout << "============" << endl;
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d ", ans[i]);
	}

	return 0;
}