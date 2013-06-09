#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;
#define task_name "o2cmax"

struct task {
    int a, b, id;
    long long start_time_a, start_time_b;

    task(int a, int b, int id) : a(a), b(b), id(id) {
        start_time_a = start_time_b = -1;
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

    int n, x;
    cin >> n;

    vector<task> tasks;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        tasks.push_back(task(x, 0, i));
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        tasks[i].b = x;
    }

    int max_a = -1, max_b = -1;
    int ind_a = -1, ind_b = -1;
    long long sum_a = 0, sum_b = 0, cmax = 0;

    vector<int> I, J;
    for (int i = 0; i < n; ++i) {
        sum_a += tasks[i].a;
        sum_b += tasks[i].b;
        cmax = max(cmax, (long long)(tasks[i].a) + tasks[i].b);

        if (tasks[i].a <= tasks[i].b) {
            I.push_back(i);
            if (max_a < tasks[i].a) {
                max_a = tasks[i].a;
                ind_a = i;
            }
        } else
        {
            J.push_back(i);
            if (max_b < tasks[i].b) {
                max_b = tasks[i].b;
                ind_b = i;
            }
        }
    }
    cmax = max(cmax, max(sum_a, sum_b));

    cout << cmax << endl;

    int r;
    if (ind_a != -1 && ind_b == -1)
        r = ind_a;
    if (ind_a == -1 && ind_b != -1)
        r = ind_b;
    if (ind_a != -1 && ind_b != -1) {
        if (max_a > max_b)
            r = ind_a;
        else
            r = ind_b;
    }


    bool inv = (r == ind_b);
    if (inv) {
        for (int i = 0; i < n; ++i) {
            swap(tasks[i].a, tasks[i].b);
        }
        swap(I, J);
    }

    int ind;

    // a
    long long time_a = 0;
    for (size_t i = 0; i < I.size(); ++i) {
        ind = I[i];
        if (ind == r) continue;
        tasks[ind].start_time_a = time_a;
        time_a += tasks[ind].a;
    }
    time_a = cmax;
    time_a -= tasks[r].a;
    tasks[r].start_time_a = time_a;
    for (size_t i = 0; i < J.size(); ++i) {
        ind = J[i];
        time_a -= tasks[ind].a;
        tasks[ind].start_time_a = time_a;
    }

    // b
    long long time_b = 0;
    tasks[r].start_time_b = time_b;
    time_b += tasks[r].b;
    for (size_t i = 0; i < I.size(); ++i) {
        int ind = I[i];
        if (ind == r) continue;
        tasks[ind].start_time_b = time_b;
        time_b += tasks[ind].b;
    }
    time_b = cmax;
    for (size_t i = 0; i < J.size(); ++i) {
        int ind = J[i];
        time_b -= tasks[ind].b;
        tasks[ind].start_time_b = time_b;
    }

    for (int i = 0; i < n; ++i) {
        printf("%lld ", inv ? tasks[i].start_time_b : tasks[i].start_time_a);
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        printf("%lld ", inv ? tasks[i].start_time_a : tasks[i].start_time_b);
    }

    return 0;
}
