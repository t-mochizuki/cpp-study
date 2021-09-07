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
using std::vector;
using std::string;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const long MOD = 1e9 + 7;

class Problem {
private:

    int N;
    string s;
    vector<vector<long>> dp;

public:
    Problem() {
        cin >> N >> s;

        dp.assign(N, vector<long>(N, 0));
    }

    void solve() {

        rep(j, N) dp[0][j] = 1;

        // 文字列sの添字は0からN-2である。
        for (int i = 1; i < N; ++i) {
            rep(j, N-i) {
                if (s[i-1] == '<') {
                    for (int k = 0; k <= j; ++k) {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= MOD;
                    }
                } else {
                    for (int k = j+1; k < N; ++k) {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }

        cout << dp[N-1][0] << endl;
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
