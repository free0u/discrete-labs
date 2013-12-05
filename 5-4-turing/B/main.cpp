#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "aplusb"

int main() {
    freopen(task_name".out", "w", stdout);

    vector<string> ans;
    ans.push_back("start: s");
    ans.push_back("accept: p3");
    ans.push_back("reject: rj");
    ans.push_back("blank: e");
    ans.push_back("");
    ans.push_back("s 0 -> s 0 >");
    ans.push_back("s 1 -> s 1 >");
    ans.push_back("s + -> s + >");
    ans.push_back("s e -> q1 e < ");
    ans.push_back("");
    ans.push_back("q1 0 -> q1 0 < ");
    ans.push_back("q1 1 -> q2 0 >");
    ans.push_back("q1 + -> p + ^");
    ans.push_back("");
    ans.push_back("q2 0 -> q2 1 >");
    ans.push_back("q2 1 -> q2 0 >");
    ans.push_back("q2 e -> q3 e <");
    ans.push_back("");
    ans.push_back("q3 0 -> q3 0 <");
    ans.push_back("q3 1 -> q3 1 <");
    ans.push_back("q3 + -> q4 + <");
    ans.push_back("");
    ans.push_back("p 0 -> p e >");
    ans.push_back("p 1 -> p e >");
    ans.push_back("p + -> p e >");
    ans.push_back("p e -> p1 e ^");
    ans.push_back("");
    ans.push_back("p1 0 -> p2 0 ^");
    ans.push_back("p1 1 -> p2 1 ^");
    ans.push_back("p1 e -> p1 e <");
    ans.push_back("");
    ans.push_back("p2 0 -> p2 0 <");
    ans.push_back("p2 1 -> p2 1 <");
    ans.push_back("p2 e -> p3 e >");
    ans.push_back("");
    ans.push_back("q4 0 -> q5 1 >");
    ans.push_back("q4 1 -> q4 1 < ");
    ans.push_back("q4 e -> q5 1 > ");
    ans.push_back("");
    ans.push_back("q5 1 -> q5 0 > ");
    ans.push_back("q5 + -> q6 + < ");
    ans.push_back("");
    ans.push_back("q6 0 -> q6 0 < ");
    ans.push_back("q6 1 -> q6 1 <");
    ans.push_back("q6 e -> s e >");
    ans.push_back("");
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
