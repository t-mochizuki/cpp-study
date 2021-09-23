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

// 桁DP
class Problem {
private:

    string K;
    int D;
    vector<vector<vector<long>>> dp;

public:
    Problem() {
        cin >> K >> D;
        int N = K.length();

        dp.assign(N+1, vector<vector<long>>(D, vector<long>(2, 0)));
        dp[0][0][0] = 1;
    }

    void solve() {
        int N = K.length();

        rep(i, N) {
            int cur = K[i] - '0';
            rep(candidate, 10) {
                if (candidate < cur) {
                    rep(d, D) rep(isless, 2) {
                        dp[i + 1][(d + candidate) % D][1] += dp[i][d][isless];
                        dp[i + 1][(d + candidate) % D][1] %= MOD;
                    }
                } else if (candidate == cur) {
                    rep(d, D) rep(isless, 2) {
                        dp[i + 1][(d + candidate) % D][isless] += dp[i][d][isless];
                        dp[i + 1][(d + candidate) % D][isless] %= MOD;
                    }
                } else {
                    rep(d, D) {
                        dp[i + 1][(d + candidate) % D][1] += dp[i][d][1];
                        dp[i + 1][(d + candidate) % D][1] %= MOD;
                    }
                }
            }
        }

        long ans = (dp[N][0][0] + dp[N][0][1] - 1 + MOD) % MOD;
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
