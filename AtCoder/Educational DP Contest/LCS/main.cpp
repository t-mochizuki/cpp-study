#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;

string memo[3005][3005];

char last(string s) {
    return s[s.size() - 1];
}

string lcs(string s, string t) {
    if (memo[s.size()][t.size()] != "") {
        return memo[s.size()][t.size()];
    }

    if (s.size() == 0 || t.size() == 0) {
        return "";
    }

    if (last(s) == last(t)) {
        char tmp = last(s);
        s.pop_back();
        t.pop_back();
        memo[s.size()][t.size()] = lcs(s, t);
        return memo[s.size()][t.size()].append(1, tmp);
    }

    string tmp = s;
    s.pop_back();
    string result1 = lcs(s, t);
    memo[s.size()][t.size()] = result1;

    s = tmp;
    t.pop_back();
    string result2 = lcs(s, t);
    memo[s.size()][t.size()] = result2;

    if (result1.size() > result2.size()) {
        return result1;
    } else {
        return result2;
    }
}

void solve() {
    string s, t; cin >> s >> t;

    for (int i = 0; i < 3005; ++i) {
        for (int j = 0; j < 3005; ++j) {
            memo[i][j] = "";
        }
    }

    cout << lcs(s, t) << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
