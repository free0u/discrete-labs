#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

string convert(int x) {
    if (x == 0) return "0";
    string res = "";
    while (x) {
        int c = x % 2;
        x /= 2;
        res = (char)('0' + c) + res;
    }
    return res;

}

int random(int m) {
    return abs(rand()) % m;
}

int main() {

    int countN = 100;
    int len = 2;
    int maxC = 5;


    for (int i = 0; i < countN; ++i) {
        ofstream out("./tests/g" + std::to_string(i) + ".in");

        vector<int> a;
        for (int i = 0; i < len; ++i) {
            a.push_back(random(maxC));
        }
        vector<int> b(a.begin(), a.end());
        sort(b.begin(), b.end());

        string r1, r2;
        for (int j = 0; j < len; ++j) {
            r1 += '|';
            r1 += convert(a[j]);
        }

        for (int j = 0; j < len; ++j) {
            r2 += '|';
            r2 += convert(b[j]);
        }

        r1.erase(r1.begin(), r1.begin() + 1);
        r2.erase(r2.begin(), r2.begin() + 1);

        out << r1[0];
        for (size_t j = 1; j < r1.size(); ++j) {
            out << ' ' << r1[j];
        }
        out << endl;
        out << r2[0];
        for (size_t j = 1; j < r2.size(); ++j) {
            out << ' ' << r2[j];
        }
    }


    return 0;
}
