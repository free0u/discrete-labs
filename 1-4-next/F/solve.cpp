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

#define task_name "nextmultiperm"

bool next_multi_perm(vi &a) {
    int n = a.size();
    int pos = n - 2;
   
    while (pos != -1 && a[pos] >= a[pos + 1]) --pos;
    if (pos == -1) return false; 
   
    int k = n - 1;
    while (a[pos] >= a[k]) --k;
    swap(a[pos], a[k]);
   
    int l = pos + 1, r = n - 1;
    while (l < r) swap(a[l++], a[r--]);
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
    vi a(n);

    rep(i, n) cin >> a[i];


    if (next_multi_perm(a)) {
        rep(i, n) cout << a[i] << " ";
    } else
        rep(i, n) cout << "0 ";


    

    return 0;
}