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



#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define sqr(i) ((i)*(i))

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<double> a(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	double avg = 0;
	for (int i = 0; i < n; ++i) {
		avg += a[i];
	}
	avg /= n;

	double sq = 0;
	for (int i = 0; i < n; ++i) {
		sq += sqr(a[i] - avg);
	}

	sq /= n;

	cout << sqrt(sq);//


	set<int> s;
	for (int i = 0; i < 10; ++i) s.insert(i);


	return 0;
}