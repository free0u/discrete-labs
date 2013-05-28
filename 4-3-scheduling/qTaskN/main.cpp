#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "f2cmax"

struct item {
    int x, y, id;
    item(int x, int y, int id) : x(x), y(y), id(id) {
    }

    bool operator < (item const& o) const {
        return min(x, y) < min(o.x, o.y);
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

    vector<item> data;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        data.push_back(item(x, 0, i + 1));
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &data[i].y);
    }

    sort(data.begin(), data.end());

    vector<item> head, tail;

    for (int i = 0; i < n; ++i) {
        if (data[i].x < data[i].y) {
            head.push_back(data[i]);
        } else
        {
            tail.push_back(data[i]);
        }
    }

    for (int i = tail.size() - 1; i >= 0; i--) {
        head.push_back(tail[i]);
    }

    long long cur_time = 0, sum_time = 0;
    for (size_t i = 0; i < head.size(); i++) {
        sum_time += head[i].x;
        cur_time = max(cur_time, sum_time);
        cur_time += head[i].y;
    }

    cout << cur_time << endl;
    for (size_t i = 0; i < head.size(); i++) {
        printf("%d ", head[i].id);
    }
    cout << endl;
    for (size_t i = 0; i < head.size(); i++) {
        printf("%d ", head[i].id);
    }


    return 0;
}
