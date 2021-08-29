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
#define bit(n, k) ((n >> k) & 1)

const int MOD = 1e9 + 7;

class Problem {
private:

    int N;
    vector<vector<int>> a;
    vector<vector<int>> dp;

public:
    Problem() {
        cin >> N;

        a.resize(N, vector<int>(N, 0));
        rep(i, N) rep(j, N) cin >> a[i][j];

        // dp[i][S]:
        // 男性1から男性iまででi組のペアを作ったとして、
        // そのペアになった女性の集合がSであるときの場合の数を求める。
        dp.resize(N+1, vector<int>(1<<N, 0));
        dp[0][0] = 1;
    }

    void solve() {
        if (N > 10) {
            terminate();
        }

        for (int i = 1; i <= N; ++i)  rep(S, 1<<N) rep(j, N) {
            // 女性jは集合Sに属し、マッチングするか。
            if (bit(S, j) == 1 && a[i-1][j] == 1) {
                dp[i][S] += dp[i-1][S^(1<<j)];
                dp[i][S] %= MOD;
            }
        }

        cout << dp[N][(1<<N) - 1] << endl;
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
