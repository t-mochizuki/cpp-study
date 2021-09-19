// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)

const long MOD = 1e9+7;

class Problem {
private:

    int N;
    vector<long> A;
    // dp[i][j]: 部分列A'をj個の部分列Bに切り分ける。
    // そのときに条件を満たす切り分け方が何通りかを求める。
    vector<vector<long>> dp;
    vector<long> cum;

public:
    Problem() {
        cin >> N;

        A.resize(N+1); A[0] = 0;
        cum.resize(N+1); cum[0] = 0;
        rep(i, 1, N+1) {
            cin >> A[i];
            if (i == 1) {
                cum[i] = A[i];
            } else {
                cum[i] = A[i] + cum[i-1];
            }
        }

        dp.assign(N+1, vector<long>(N+1, 0));
        dp[1][0] = dp[1][1] = 1;
    }

    void solve() {
        if (N > 500) {
            terminate();
        }

        for (int i{1}; i <= N; ++i) {
            for (int j{1}; j <= i; ++j) {
                int jj = j-1;
                for (int ii{jj}; ii < i; ++ii) {
                    long sum = cum[i] - cum[ii];

                    if (sum % j == 0) {
                        dp[i][j] = (dp[i][j] + dp[ii][jj]) % MOD;
                    }
                }
            }
        }

        long y = 0;
        for (int k{1}; k <= N; ++k) {
            y = (y + dp[N][k]) % MOD;
        }
        cout << y << endl;
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
