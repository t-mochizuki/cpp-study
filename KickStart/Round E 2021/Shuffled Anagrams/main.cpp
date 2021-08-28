// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::next_permutation;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve(int x) {
    string S; cin >> S;

    if (S.length() > 8) {
        terminate();
    }

    vector<int> v;
    rep(i, S.length()) v.push_back(i);

    bool found = true;
    do {
        found = true;
        rep(i, S.length()) {
            if (S[i] == S[v[i]]) {
                found = false;
                break;
            }
        }

        if (found) break;
    } while (std::next_permutation(v.begin(), v.end()));

    string T;
    for (auto i : v) {
        T.push_back(S[i]);
    }

    if (found) cout << "Case #" << x << ": " << T << endl;
    else cout << "Case #" << x << ": " << "IMPOSSIBLE" << endl;
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
