#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "postfixlogic"

int main() {
    freopen(task_name".out", "w", stdout);

    vector<string> ans;
    ans.push_back("2");
    ans.push_back("");
    ans.push_back("S 0 _ -> S _ > 0 >");
    ans.push_back("S 1 _ -> S _ > 1 >");
    ans.push_back("S o _ -> or o ^ _ <");
    ans.push_back("S a _ -> and a ^ _ <");
    ans.push_back("S _ _ -> output _ ^ _ < ");
    ans.push_back("");
    ans.push_back("output _ 0 -> AC 0 ^ _ ^");
    ans.push_back("output _ 1 -> AC 1 ^ _ ^");
    ans.push_back("");
    ans.push_back("or o 0 -> or0 o ^ _ <");
    ans.push_back("or o 1 -> or1 o ^ _ <");
    ans.push_back("");
    ans.push_back("or0 o 0 -> S _ > 0 >");
    ans.push_back("or0 o 1 -> S _ > 1 >");
    ans.push_back("or1 o 0 -> S _ > 1 >");
    ans.push_back("or1 o 1 -> S _ > 1 >");
    ans.push_back("");
    ans.push_back("and a 0 -> and0 a ^ _ <");
    ans.push_back("and a 1 -> and1 a ^ _ <");
    ans.push_back("");
    ans.push_back("and0 a 0 -> S _ > 0 >");
    ans.push_back("and0 a 1 -> S _ > 0 >");
    ans.push_back("and1 a 0 -> S _ > 0 >");
    ans.push_back("and1 a 1 -> S _ > 1 >");
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
