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

const int MOD = 1e9 + 7;

class Problem {
private:

    int H, W;
    vector<string> a;
    vector<vector<int>> dp;

public:
    Problem() {
        cin >> H >> W;

        a.resize(H);
        rep(i, H) cin >> a[i];

        dp.assign(H+1, vector<int>(W+1, 0));

        dp[1][1] = 1;
    }

    void solve() {
        for (int i = 1; i <= H; ++i) for (int j = 1; j <= W; ++j) {
            if (i == 1 && j == 1) continue;

            if (a[i-1][j-1] == '#') dp[i][j] = 0;
            else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }

        cout << dp[H][W] << endl;
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
