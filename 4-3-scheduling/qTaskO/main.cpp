#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
#define task_name "qsumci"

struct task {
    int p, id;

    task(int p, int id) : p(p), id(id) {}

    bool operator < (task const& o) const {
        return o.p < p;
    }
};

struct machine {
    int t, id, d;

    machine(int t, int id) : t(t), id(id), d(1) {}

    bool operator < (machine const &o) const {
        return d * t < o.d * o.t;
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

    int n, m, x;
    cin >> n >> m;

    vector<task> tasks;
    for (int i = 0; i < n; ++i) {
        scanf("%d ", &x);
        tasks.push_back(task(x, i));
    }

    multiset<machine> q;
    vector<int> machine_time(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d ", &machine_time[i]);
        q.insert(machine(machine_time[i], i));
    }

    vector<vector<int> > schedule(m);
    for (int i = 0; i < n; ++i) {
        machine m = *q.begin();
        q.erase(q.begin());
        schedule[m.id].push_back(i);
        m.d++;
        q.insert(m);
    }

    long long ans = 0, t;
    vector<int> ans_machine(n);
    vector<long long> ans_time(n);

    sort(tasks.begin(), tasks.end());

    for (int i = 0; i < m; i++) {
        t = 0;
        for (int j = schedule[i].size() - 1; j >= 0; --j) {
            int ind = schedule[i][j];
            ans_time[tasks[ind].id] = t;
            t += tasks[ind].p * machine_time[i];
            ans += t;
            ans_machine[tasks[ind].id] = i;
        }
    }

    cout << ans << endl;
    for (int i = 0; i < n; ++i) {
        printf("%d %lld\n", ans_machine[i] + 1, ans_time[i]);
    }

    return 0;
}
