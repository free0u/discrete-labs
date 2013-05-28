#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
#define task_name "p1sumu"

struct task {
    int p, d, id;

    long long start_time;

    task(int p, int d, int id) : p(p), d(d), id(id) {
    }

    bool operator < (task const& o) const {
        return d < o.d;
    }
};

struct my_compare {
  bool operator()(task const& a, task const& b) const {
      return a.p > b.p;
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

    int n, p, d;
    cin >> n;
    vector<task> tasks;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &p, &d);
        tasks.push_back(task(p, d, i));
    }

    sort(tasks.begin(), tasks.end());

    long long time = 0;
    multiset<task, my_compare> s;
    for (int i = 0; i < n; ++i) {
        tasks[i].start_time = time;
        s.insert(tasks[i]);

        time += tasks[i].p;

        if (time > tasks[i].d) {
            task t = *s.begin();
            s.erase(s.begin());
            time -= t.p;
        }
    }

    vector<long long> ans(n, -1);
    for (set<task, my_compare>::iterator it = s.begin(); it != s.end(); it++) {
        ans[it->id] = it->start_time;
    }

    cout << s.size() << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        printf("%lld ", ans[i]);
    }

    return 0;
}
