// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class Problem {
private:

    string s, t;
    vector<vector<string>> dp;

public:
    Problem() {
        cin >> s >> t;

        dp.assign(t.length()+1, vector<string>(s.length()+1, ""));
    }

    void solve() {
        rep(row, t.length()+1) rep(col, s.length()+1) {
            if (col == 0 || row == 0) continue;

            dp[row][col] = s[col-1] == t[row-1] ? dp[row-1][col-1] + string(1, s[col-1]) : "";

            if (dp[row-1][col].length() > dp[row][col].length()) {
                dp[row][col] = dp[row-1][col];
            }

            if (dp[row][col-1].length() > dp[row][col].length()) {
                dp[row][col] = dp[row][col-1];
            }
        }

        cout << dp[t.length()][s.length()] << endl;
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Problem p;
        p.solve();
    }
#else
    Problem p;
    p.solve();
#endif

    return 0;
}
