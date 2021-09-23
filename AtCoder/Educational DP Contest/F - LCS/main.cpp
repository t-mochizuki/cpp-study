// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::reverse;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class Problem {
private:

    string s, t;
    vector<vector<int>> dp;

public:
    Problem() {
        cin >> s >> t;

        dp.assign(t.length()+1, vector<int>(s.length()+1, 0));
    }

    void debug() {
        rep(row, t.length()+1) {
            rep(col, s.length()+1) {
                if (col == 0) {
                    cout << dp[row][col];
                } else {
                    cout << " " << dp[row][col];
                }
            }
            cout << endl;
        }
    }

    void solve() {
        rep(row, t.length()+1) rep(col, s.length()+1) {
            if (col == 0 || row == 0) continue;

            dp[row][col] = s[col-1] == t[row-1] ? dp[row-1][col-1] + 1 : 0;

            if (dp[row-1][col] > dp[row][col]) {
                dp[row][col] = dp[row-1][col];
            }

            if (dp[row][col-1] > dp[row][col]) {
                dp[row][col] = dp[row][col-1];
            }
        }

        string ans;
        int row = t.length();
        int col = s.length();
        while (row > 0 && col > 0) {
            if (dp[row][col] > dp[row-1][col] && dp[row][col] > dp[row][col-1]) {
                ans.append(1, s[col-1]);
                col--;
                row--;
            } else if (dp[row][col] == dp[row-1][col]) {
                row--;
            } else if (dp[row][col] == dp[row][col-1]) {
                col--;
            }
        }

        reverse(ans.begin(), ans.end());
        cout << ans << endl;
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
