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
    // 文字列sのi番目まで条件を満たすときに、順列Pのi+1番目の値が決まる。
    // この値より小さい値がj個あり、
    // この値より大きい値がk個あるとする。
    // そのときに条件を満たす順列が何通りかを求める。
    vector<vector<vector<long>>> dp;

public:
    Problem() {
        cin >> N >> s;

        s = " " + s;

        if (N > 100) {
            terminate();
        }

        dp.assign(N, vector<vector<long>>(N, vector<long>(N, 0)));
    }

    void solve() {

        for (int p = 1; p <= N; ++p) {
            dp[0][p-1][N-p] = 1;
        }

        for (int i = 1; i <= N-1; ++i) {
            if (s[i] == '<') {
                // int z = q-p;
                for (int z = 1; z <= N-i; ++z) {
                    rep(j, N) rep(k, N) {
                        int kk = k-z;
                        int whole = j+k-1;
                        int jj = whole-kk;
                        if ((0 <= jj && jj <= N-1) && (0 <= kk && kk <= N-1)) {
                            dp[i]/*[q]*/[jj][kk] += dp[i-1]/*[p]*/[j][k];
                        }
                    }
                }
            } else {
                // int z = p-q;
                for (int z = 1; z <= N-i; ++z) {
                    rep(k, N) rep(j, N) {
                        int jj = j-z;
                        int whole = j+k-1;
                        int kk = whole-jj;
                        if ((0 <= jj && jj <= N-1) && (0 <= kk && kk <= N-1)) {
                            dp[i]/*[q]*/[jj][kk] += dp[i-1]/*[p]*/[j][k];
                        }
                    }
                }
            }
        }

        long ans = dp[N-1][0][0] % MOD;

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
