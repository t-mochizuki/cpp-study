#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;

void solve(int x) {
    string s; cin >> s;

    vector<int> kv;
    for (int i = 0; i < s.size(); ++i) {
        string tmp = s.substr(i, 4);
        cout << tmp << endl;
        if (tmp == string("KICK")) {
            kv.push_back(i);
        }
    }

    // cout << "KICK" << endl;
    // for (auto v : kv) {
    //     cout << v << endl;
    // }

    vector<int> sv;
    for (int i = 0; i < s.size(); ++i) {
        string tmp = s.substr(i, 5);
        if (tmp == string("START")) {
            sv.push_back(i);
        }
    }

    // cout << "START" << endl;
    // for (auto v : sv) {
    //     cout << v << endl;
    // }

    int kick = 0;
    int start = 0;
    int y = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (kv.empty()) {
            break;
        }
        if (kv[kick] == i) {
            kick++;
        }
        if (sv.empty()) {
            break;
        }
        if (sv[start] == i) {
            start++;
            y += kick;
        }
    }

    cout << "Case #" << x << ": " << y << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#else
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#endif

    return 0;
}
