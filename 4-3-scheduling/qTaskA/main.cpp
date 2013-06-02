#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <limits>
#include <set>
#include <unistd.h>

using namespace std;
#define task_name "cheese"

struct edge;

struct vertex {
    int n;
    bool used;
    vector<edge*> edges;

    vertex(int n) : n(n), used(false) {}
};

struct edge {
    vertex* x;
    vertex* y;
    edge* r;
    long long f, c;

    edge(vertex * x, vertex * y, long long c) : x(x), y(y), r(NULL), f(0), c(c) {}
};

struct graph {
    vector<vertex*> v;
    long long m;

    graph(int n) {
        v.resize(n);
        for (size_t i = 0; i < v.size(); i++) {
            v[i] = new vertex(i);
        }
    }

    void add_edge(int x, int y, long long c) {
        edge * e = new edge(v[x], v[y], c);
        edge * er = new edge(v[y], v[x], 0);
        e->r = er;
        er->r = e;
        v[x]->edges.push_back(e);
        v[y]->edges.push_back(er);
    }

    long long max_flow(int s, int t) {
        long long flow = 0;
        for (long long scale = 1L << 60; scale > 0; scale >>= 2) {
            for (size_t i = 0; i < v.size(); i++) {
                v[i]->used = false;
            }
            m = numeric_limits<long long>::max();
            while (dfs(v[s], v[t], scale, m)) {
                for (size_t i = 0; i < v.size(); i++) {
                    v[i]->used = false;
                }
                flow += m;
            }
        }
        return flow;
    }

    bool dfs(vertex * x, vertex * t, long long scale, long long f) {
        if (x == t) {
            m = f;
            return true;
        }
        x->used = true;
        for (size_t i = 0; i < x->edges.size(); ++i) {
            if (x->edges[i]->c - x->edges[i]->f >= scale && !x->edges[i]->y->used
                    && dfs(x->edges[i]->y, t, scale, min(f, x->edges[i]->c - x->edges[i]->f))) {
                x->edges[i]->f += m;
                x->edges[i]->r->f -= m;
                return true;
            }
        }
        return false;
    }
};

int main() {
    freopen("cheese.in", "r", stdin);
    freopen("cheese.out", "w", stdout);
    long long PREC = 100000;

    int n, m, x, y, z;
    scanf("%d %d", &n, &m);

    vector<long long> p(n), r(n), d(n);

    long long sp = 0;

    for (size_t i = 0; i < d.size(); i++) {
        scanf("%d %d %d", &x, &y, &z);
        p[i] = x * PREC;
        sp += p[i];
        r[i] = y * PREC;
        d[i] = z * PREC;
    }
    vector<long long> s(m);
    for (size_t j = 0; j < s.size(); j++) {
        scanf("%d", &x);
        s[j] = -x;
    }
    sort(s.begin(), s.end());
    long long sum = 0;
    for (size_t i = 0; i < s.size(); i++) {
        s[i] = -s[i];
        sum += s[i];
    }

    long long left = -1L * 10000000 * 100000;
    long long right = 1L * 10000000 * 100000;
    while (right - left > 1) {
        long long middle = (left + right) / 2;
        set<long long> ts;
        for (size_t i = 0; i < p.size(); i++) {
            ts.insert(r[i]);
            ts.insert(d[i] + middle);
        }
        vector<long long> t(ts.begin(), ts.end());

        graph * g = new graph(1 + n + m * (t.size() - 1) + t.size() - 1 + 1);
        for (size_t i = 0; i < p.size(); i++) {
            g->add_edge(0, i + 1, p[i]);
            for (size_t k = 0; k + 1 < t.size(); k++) {
                if (r[i] <= t[k] && t[k + 1] <= d[i] + middle) {
                    int sh = n + 1 + k * m;
                    for (size_t j = 0; j < s.size(); j++) {
                        long long c = (s[j] - (j + 1 < s.size() ? s[j + 1] : 0))
                                * (t[k + 1] - t[k]);
                        g->add_edge(i + 1, sh + j, c);
                    }
                }
            }
        }
        for (size_t k = 0; k + 1 < t.size(); k++) {
            int sh = n + 1 + k * m;
            for (size_t j = 0; j < s.size(); j++) {
                long long c = (j + 1)
                        * (s[j] - (j + 1 < s.size() ? s[j + 1] : 0))
                        * (t[k + 1] - t[k]);
                g->add_edge(sh + j, 1 + n + m * (t.size() - 1) + k, c);
            }
            g->add_edge(1 + n + m * (t.size() - 1) + k, 1 + n + m
                    * (t.size() - 1) + t.size() - 1, sum
                    * (t[k + 1] - t[k]));
        }
        long long flow = g->max_flow(0, 1 + n + m * (t.size() - 1) + t.size() - 1);
        if (flow == sp)
            right = middle;
        else
            left = middle;
    }
    printf("%.9f", (max((double)right, 0.0) / PREC));
    return 0;
}
