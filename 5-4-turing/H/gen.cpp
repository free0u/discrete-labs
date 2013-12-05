#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

vector<int> convert(int x, int base) {
    vector<int> res;
    while (x) {
        res.push_back(x % base);
        x /= base;
    }
    return res;
}

int main() {


    for (int i = 0; i < 100; ++i) {
        ofstream out("gen" + to_string(i) + ".in");

        vector<int> base2 = convert(i, 2);
        vector<int> base3 = convert(i, 3);

        reverse(base2.begin(), base2.end());
        reverse(base3.begin(), base3.end());

        if (base2.size() == 0) {
            out << "0" << endl;
            out << "0" << endl;
            continue;
        }


        for (size_t j = 0; j < base3.size(); ++j) {
            out << base3[j] << " ";
        }
        out << endl;
        for (size_t j = 0; j < base2.size(); ++j) {
            out << base2[j] << " ";
        }
        out << endl;

    }


    return 0;
}
