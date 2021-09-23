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
    vector<int> dp;

public:
    Problem() {
        cin >> N;

        a.resize(N, vector<int>(N, 0));
        rep(i, N) rep(j, N) cin >> a[i][j];

        // dp[S]:
        // 男性とペアを作った女性の集合がSであるときの場合の数を求める。
        dp.resize(1<<N, 0);
        dp[0] = 1;
    }

    void solve() {
        for (int S = 1; S < 1<<N; ++S) rep(j, N) {
            int i = __builtin_popcount(S);

            // 女性jは集合Sに属し、マッチングするか。
            if (bit(S, j) == 1 && a[i-1][j] == 1) {
                dp[S] += dp[S^(1<<j)];
                dp[S] %= MOD;
            }
        }

        cout << dp[(1<<N) - 1] << endl;
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
