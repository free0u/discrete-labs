#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "convertto2"

int main() {
    freopen(task_name".out", "w", stdout);

    vector<string> ans;
    ans.push_back("start: s");
    ans.push_back("accept: ac");
    ans.push_back("reject: rj");
    ans.push_back("blank: e");
    ans.push_back("");
    ans.push_back("s 0 -> add_ 0 <");
    ans.push_back("s 1 -> add_ 1 <");
    ans.push_back("s 2 -> add_ 2 <");
    ans.push_back("add_ e -> begin _ >");
    ans.push_back("");
    ans.push_back("begin 0 -> even 0 > ");
    ans.push_back("begin 1 -> odd 1 >");
    ans.push_back("begin 2 -> even 2 >");
    ans.push_back("");
    ans.push_back("even 0 -> even 0 >");
    ans.push_back("even 1 -> odd 1 >");
    ans.push_back("even 2 -> even 2 >");
    ans.push_back("even e -> push0 e <");
    ans.push_back("");
    ans.push_back("odd 0 -> odd 0 >");
    ans.push_back("odd 1 -> even 1 >");
    ans.push_back("odd 2 -> odd 2 >");
    ans.push_back("odd e -> push1 e <");
    ans.push_back("");
    ans.push_back("push0 0 -> push0 0 <");
    ans.push_back("push0 1 -> push0 1 <");
    ans.push_back("push0 2 -> push0 2 <");
    ans.push_back("push0 _ -> push0 _ <");
    ans.push_back("push0 e -> to_begin 0 >");
    ans.push_back("");
    ans.push_back("push1 0 -> push1 0 <");
    ans.push_back("push1 1 -> push1 1 <");
    ans.push_back("push1 2 -> push1 2 <");
    ans.push_back("push1 _ -> push1 _ <");
    ans.push_back("push1 e -> to_begin 1 >");
    ans.push_back("");
    ans.push_back("to_begin 0 -> to_begin 0 >");
    ans.push_back("to_begin 1 -> to_begin 1 >");
    ans.push_back("to_begin 2 -> to_begin 2 >");
    ans.push_back("to_begin _ -> q _ >");
    ans.push_back("");
    ans.push_back("q 0 -> q 0 >");
    ans.push_back("q 1 -> qc 0 >");
    ans.push_back("q 2 -> q 1 >");
    ans.push_back("q e -> check e <");
    ans.push_back("");
    ans.push_back("qc 0 -> qc 1 >");
    ans.push_back("qc 1 -> q 2 >");
    ans.push_back("qc 2 -> qc 2 >");
    ans.push_back("qc e -> check e <");
    ans.push_back("");
    ans.push_back("check 0 -> check 0 <");
    ans.push_back("check 1 -> cont 1 <");
    ans.push_back("check 2 -> cont 2 <");
    ans.push_back("check _ -> output _ ^");
    ans.push_back("");
    ans.push_back("cont 0 -> cont 0 <");
    ans.push_back("cont 1 -> cont 1 <");
    ans.push_back("cont 2 -> cont 2 <");
    ans.push_back("cont _ -> begin _ >");
    ans.push_back("");
    ans.push_back("output _ -> output e >");
    ans.push_back("output 0 -> output e >");
    ans.push_back("output e -> jmp_num e ^");
    ans.push_back("");
    ans.push_back("jmp_num 0 -> jmp_begin 0 <");
    ans.push_back("jmp_num 1 -> jmp_begin 1 <");
    ans.push_back("jmp_num 2 -> jmp_begin 2 <");
    ans.push_back("jmp_num e -> jmp_num e <");
    ans.push_back("");
    ans.push_back("jmp_begin 0 -> jmp_begin 0 <");
    ans.push_back("jmp_begin 1 -> jmp_begin 1 <");
    ans.push_back("jmp_begin 2 -> jmp_begin 2 <");
    ans.push_back("jmp_begin e -> ac e >");
    ans.push_back("");
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
