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

#define rep(i, n) for (int i = 0; i < (n); ++i)

const int MOD = 1e9 + 7;

class Problem {
private:

    int N, K;
    vector<int> a;
    vector<vector<int>> dp;

public:
    Problem() {
        cin >> N >> K;

        a.resize(N+1);
        for (int i = 1; i <= N; ++i) cin >> a[i];

        // 子供1から子供iまでにj個の飴を分け合う方法は何通りかを求める。
        dp.assign(N+1, vector<int>(K+1, 0));
        dp[0][0] = 1;
    }

    void solve() {
        if (K > 10000) {
            terminate();
        }

        for (int i = 1; i <= N; ++i) rep(j, K+1) rep(k, a[i]+1) {
            if (j-k >= 0) {
                dp[i][j] += dp[i-1][j-k];
                dp[i][j] %= MOD;
            }
        }

        cout << dp[N][K] << endl;
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
