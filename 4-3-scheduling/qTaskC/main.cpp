#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
#define task_name "p1outtreewc"

struct DSU {
    vector<int> data;

    DSU() {}
    DSU(int n) {
        for (int i = 0; i < n; ++i) {
            data.push_back(i);
        }
    }

    int get(int x) {
        if (data[x] != x) {
            data[x] = get(data[x]);
        }
        return data[x];
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        data[y] = x;
    }
};

struct task {
    long long p, w;
    int id, par, prev;

    static int root;

    task(long long p, long long w, int id) : p(p), w(w), id(id), par(-1), prev(id) {}

    void add(task * child) {
        p += child->p;
        w += child->w;

        child->par = prev;
        prev = child->prev;
    }

    bool operator < (task const& o) const {
        if (id == o.id) return false;
        if (id == root) return true;
        if (o.id == root) return false;

        long long d = w * o.p - p * o.w;
        if (d == 0) return id < o.id;
        return d < 0;
    }
};

int task::root = 0;

struct comp {
    bool operator()(task* const& a, task* const& b) {
        return (*a) < (*b);
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

    int n, x, y;
    cin >> n;

    vector<task> jobs;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        jobs.push_back(task(x, 0, i));
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        jobs[i].w = x;
    }

    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &x, &y);
        --x; --y;
        jobs[x].par = y;
    }
    for (int i = 0; i < n; ++i) {
        if (jobs[i].par == -1) {
            task::root = i;
            break;
        }
    }

    DSU dsu = DSU(n);
    vector<task> J(jobs.begin(), jobs.end());
    set<task*, comp> s;
    for (size_t i = 0; i < jobs.size(); ++i) {
        s.insert(&J[i]);
    }

    while (s.size() > 1) {
        set<task*, comp>::iterator t_it = --s.end();
        task* t = *t_it;
        s.erase(t_it);

        int ind = dsu.get(t->par);
        s.erase(&J[ind]);

        J[ind].add(t);

        dsu.unite(J[ind].id, t->id);
        s.insert(&J[ind]);
    }

    int h = (*s.begin())->prev;
    vector<int> pi;
    while (h != -1) {
        pi.push_back(h);
        h = J[h].par;
    }

    reverse(pi.begin(), pi.end());

    long long time = 0, res = 0;
    vector<long long> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[pi[i]] = time;
        time += jobs[pi[i]].p;
        res += time * jobs[pi[i]].w;
    }

    cout << res << endl;
    for (int i = 0; i < n; ++i) {
        printf("%lld ", ans[i]);
    }

    return 0;
}
