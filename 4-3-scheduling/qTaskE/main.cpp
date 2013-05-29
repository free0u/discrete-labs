#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
#define task_name "p1sumwu"

struct task {
    int d, w, id;

    task(int d, int w, int id) : d(d), w(w), id(id) {
    }

    bool operator < (task const& o) const {
        return d < o.d;
    }
};

struct my_compare {
    bool operator()(task const& a, task const& b) const {
        return a.w == b.w ? a.d > b.d : a.w < b.w;
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

    int n;
    cin >> n;
    int d, w;

    long long sum_w = 0;

    vector<task> tasks;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &d, &w);
        sum_w += w;
        tasks.push_back(task(d, w, i));
    }

    sort(tasks.begin(), tasks.end());

    multiset<task, my_compare> s;
    long long time = 1;
    for (int i = 0; i < n; ++i) {
        if (tasks[i].d >= time ) {
            s.insert(tasks[i]);
            time++;
        } else
        {
            multiset<task>::iterator it = s.begin();
            if (it->w < tasks[i].w) {
                s.erase(it);
                s.insert(tasks[i]);
            }
        }
    }

    vector<task> complete(s.begin(), s.end());
    sort(complete.begin(), complete.end());

    vector<long long> ans(n, -1);
    time = 0;
    for (size_t i = 0; i < complete.size(); ++i) {
        sum_w -= complete[i].w;
        ans[complete[i].id] = time++;
    }

    cout << sum_w << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        if (ans[i] == -1) {
            printf("%lld ", time++);
        } else
        {
            printf("%lld ", ans[i]);
        }
    }

    return 0;
}
