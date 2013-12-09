#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
//; comment
//; * 10|_
//; # 10|
//; $ 01
//; @ 0_
void print(string const& from,
           char fa, char fb, char fc,
           string const& to,
           char ta, char da,
           char tb, char db,
           char tc, char dc) {
    if (fa == '*') {
        print(from, '1', fb, fc, to, (ta == '*' ? '1' : ta), da, tb, db, tc, dc);
        print(from, '0', fb, fc, to, (ta == '*' ? '0' : ta), da, tb, db, tc, dc);
        print(from, '|', fb, fc, to, (ta == '*' ? '|' : ta), da, tb, db, tc, dc);
        print(from, '_', fb, fc, to, (ta == '*' ? '_' : ta), da, tb, db, tc, dc);
    } else
    if (fa == '#') {
        print(from, '1', fb, fc, to, (ta == '#' ? '1' : ta), da, tb, db, tc, dc);
        print(from, '0', fb, fc, to, (ta == '#' ? '0' : ta), da, tb, db, tc, dc);
        print(from, '|', fb, fc, to, (ta == '#' ? '|' : ta), da, tb, db, tc, dc);
    } else
    if (fa == '$') {
        print(from, '1', fb, fc, to, (ta == '$' ? '1' : ta), da, tb, db, tc, dc);
        print(from, '0', fb, fc, to, (ta == '$' ? '0' : ta), da, tb, db, tc, dc);
    } else
    if (fa == '@') {
        print(from, '_', fb, fc, to, (ta == '@' ? '_' : ta), da, tb, db, tc, dc);
        print(from, '0', fb, fc, to, (ta == '@' ? '0' : ta), da, tb, db, tc, dc);
    } else


    if (fb == '*') {
        print(from, fa, '1', fc, to, ta, da, (tb == '*' ? '1' : tb), db, tc, dc);
        print(from, fa, '0', fc, to, ta, da, (tb == '*' ? '0' : tb), db, tc, dc);
        print(from, fa, '|', fc, to, ta, da, (tb == '*' ? '|' : tb), db, tc, dc);
        print(from, fa, '_', fc, to, ta, da, (tb == '*' ? '_' : tb), db, tc, dc);
    } else
    if (fb == '#') {                         
        print(from, fa, '1', fc, to, ta, da, (tb == '#' ? '1' : tb), db, tc, dc);
        print(from, fa, '0', fc, to, ta, da, (tb == '#' ? '0' : tb), db, tc, dc);
        print(from, fa, '|', fc, to, ta, da, (tb == '#' ? '|' : tb), db, tc, dc);
    } else
    if (fb == '$') {                         
        print(from, fa, '1', fc, to, ta, da, (tb == '$' ? '1' : tb), db, tc, dc);
        print(from, fa, '0', fc, to, ta, da, (tb == '$' ? '0' : tb), db, tc, dc);
    } else
    if (fb == '@') {                         
        print(from, fa, '_', fc, to, ta, da, (tb == '@' ? '_' : tb), db, tc, dc);
        print(from, fa, '0', fc, to, ta, da, (tb == '@' ? '0' : tb), db, tc, dc);
    } else

// c
    if (fc == '*') {
        print(from, fa, fb, '1', to, ta, da, tb, db, (tc == '*' ? '1' : tc), dc);
        print(from, fa, fb, '0', to, ta, da, tb, db, (tc == '*' ? '0' : tc), dc);
        print(from, fa, fb, '|', to, ta, da, tb, db, (tc == '*' ? '|' : tc), dc);
        print(from, fa, fb, '_', to, ta, da, tb, db, (tc == '*' ? '_' : tc), dc);
    } else
    if (fc == '#') {                              
        print(from, fa, fb, '1', to, ta, da, tb, db, (tc == '#' ? '1' : tc), dc);
        print(from, fa, fb, '0', to, ta, da, tb, db, (tc == '#' ? '0' : tc), dc);
        print(from, fa, fb, '|', to, ta, da, tb, db, (tc == '#' ? '|' : tc), dc);
    } else
    if (fc == '$') {                              
        print(from, fa, fb, '1', to, ta, da, tb, db, (tc == '$' ? '1' : tc), dc);
        print(from, fa, fb, '0', to, ta, da, tb, db, (tc == '$' ? '0' : tc), dc);
    } else
    if (fc == '@') {                              
        print(from, fa, fb, '_', to, ta, da, tb, db, (tc == '@' ? '_' : tc), dc);
        print(from, fa, fb, '0', to, ta, da, tb, db, (tc == '@' ? '0' : tc), dc);
    } else
    {


    cout << from << " ";
    cout << fa << " ";
    cout << fb << " ";
    cout << fc << " ";
    cout << "->" << " ";
    cout << to << " ";
    cout << ta << " ";
    cout << da << " ";
    cout << tb << " ";
    cout << db << " ";
    cout << tc << " ";
    cout << dc << endl;
    }
}

int main() {
    freopen("sorting.my.txt", "r", stdin);
    freopen("sorting.txt", "w", stdout);

    int n;
    cin >> n;
    cout << n << endl;
    string s;
    while (getline(cin, s)) {
        if (s == "") continue;
        if (s[0] == ';') continue;
        if (s[0] == ' ') continue;
        stringstream in(s);
        string from;
        in >> from;
        char fa, fb, fc, ta, tb, tc, da, db, dc;
        in >> fa >> fb >> fc;
        in >> s;
        string to;
        in >> to;
        in >> ta >> da >> tb >> db >> tc >> dc;
        print(from, fa, fb, fc, to, ta, da, tb, db, tc, dc);
    }

    return 0;
}
