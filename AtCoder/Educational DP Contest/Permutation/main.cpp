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

        s = " " + s;

        dp.assign(N+1, vector<long>(N, 0));
    }

    void solve() {

        rep(j, N) dp[1][j] = 1;

        for (int i = 1; i <= N-1; ++i) {
            rep(j, N-i) {
                if (s[i] == '<') {
                    for (int k = 0; k <= j; ++k) {
                        dp[i+1][j] += dp[i][k];
                        dp[i+1][j] %= MOD;
                    }
                } else {
                    for (int k = j+1; k < N; ++k) {
                        dp[i+1][j] += dp[i][k];
                        dp[i+1][j] %= MOD;
                    }
                }
            }
        }

        cout << dp[N][0] << endl;
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
