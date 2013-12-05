#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "zero"

int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<string> ans;

    ans.push_back("start: s");
    ans.push_back("accept: ac");
    ans.push_back("reject: rj");
    ans.push_back("blank: _");
    ans.push_back("s _ -> ac _ ^");
    ans.push_back("s 0 -> n _ >");
    ans.push_back("n 0 -> s _ >");
    ans.push_back("n _ -> rj _ >");

    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
