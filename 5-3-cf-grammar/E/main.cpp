#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define task_name "cf"


vector<vector<vector<vector<int> > > > data;
string pattern;
int len;
vector<pair<char, string> > rules;
vector<vector<string> > a;
vector<vector<int> > inds;

int is_possible(int rule_ind, int rule_from, int from, int to) {
    if (to >= 0 && data[rule_ind][rule_from][from][to] != -1) {
        return data[rule_ind][rule_from][from][to];
    }
    int result = 0;

    string &rule = rules[rule_ind].second;
    if (rule_from < (int)rule.size()) { // rule not empty
        char c = rule[rule_from];
        if (c >= 'a' && c <= 'z') { // terminal
            if (from > to) { // substring empty
                data[rule_ind][rule_from][from][to] = 0;
                return 0;
            }

            if (pattern[from] != c) {
                data[rule_ind][rule_from][from][to] = 0;
                return 0;
            }
            result = is_possible(rule_ind, rule_from + 1, from + 1, to);
            data[rule_ind][rule_from][from][to] = result;
            return result;
        } else { // terminal
            for (int d = from - 1 + 1; d <= to; ++d) {
                // [from;d] and [d+1;to]
                for (size_t i = 0; i < inds[c - 'A'].size(); ++i) {
                    int ind = inds[c - 'A'][i];
                    //string &new_rule = rules[inds[c - 'A'][i]].second;
                    if (c == rules[ind].second[0]) continue;
                    int temp_res = is_possible(ind, 0, from, d);
                    data[ind][0][from][d] = temp_res;
                    if (temp_res) {
                        int temp_res2 = is_possible(rule_ind, rule_from + 1, d+1, to);
                        data[rule_ind][rule_from + 1][d+1][to] = temp_res2;
                        if (temp_res2) {
                            data[rule_ind][rule_from][from][to] = 1;
                            return 1;
                        }
                    }
                }
            }
            data[rule_ind][rule_from][from][to] = 0;
            return 0;
        }
    } else { // rule is empty
        if (from > to) { // substring empty
            result = 1;
        } else {
            result = 0;
        }
        data[rule_ind][rule_from][from][to] = result;
        return result;
    }


    data[rule_ind][rule_from][from][to] = result;
    return result;
}


int main() {
#ifndef HOME_free0u
    freopen(task_name".in", "r", stdin);
    freopen(task_name".out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    vector<bool> is_term(26, false);

    string start, s;
    int n;
    cin >> n >> start; getchar();
    a.assign(26, vector<string>());
    inds.assign(26, vector<int>());
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        char from = s[0];
        is_term[from - 'A'] = true;
        size_t l = s.length();
        if (l > 4)
            s = s.substr(5, l - 5);
        else
            s = "";
        a[from - 'A'].push_back(s);
        rules.push_back(make_pair(from - 'A', s));
        inds[from - 'A'].push_back(rules.size() - 1);

        for (size_t j = 0; j < s.size(); ++j) {
            if (s[j] >= 'A' && s[j] <= 'Z') {
                is_term[s[j] - 'A'] = true;
            }
        }
    }


    cin >> pattern;
    len = pattern.size();

    data.assign(n, vector<vector<vector<int> > >
                (6, vector<vector<int> >
                 (len + 1, vector<int> (len + 1, -1)))
                );

    char start_char = start[0] - 'A';
    for (size_t i = 0; i < inds[start_char].size(); ++i) {
        int ind = inds[start_char][i];
        if (is_possible(ind, 0, 0, len - 1) == 1) {
            cout << "yes";
            return 0;
        }
    }
    cout << "no";

    return 0;
}
