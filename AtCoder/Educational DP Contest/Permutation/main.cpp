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
    vector<vector<vector<vector<long>>>> dp;

public:
    Problem() {
        cin >> N >> s;

        s = " " + s;

        dp.assign(N, vector<vector<vector<long>>>(N+1, vector<vector<long>>(N, vector<long>(N, 0))));
    }

    void solve() {

        if (N > 20) {
            terminate();
        }

        for (int p = 1; p <= N; ++p) {
            dp[0][p][p-1][N-p] = 1;
        }

        for (int i = 1; i <= N-1; ++i) {
            if (s[i] == '<') {
                for (int p = 1; p <= N; ++p) for (int q = 1; q <= N; ++q) {
                    if (p < q) {
                        rep(j, N) rep(k, N) {
                            // q=p+1のときにk'はk-1になる。
                            // q=p+2のときにk'はk-2になる。
                            // q=p+zのときにk'はk-zになる。
                            int z = q-p;
                            int kk = k-z;
                            int whole = j+k-1;
                            int jj = whole-kk;
                            if ((0 <= jj && jj <= N-1) && (0 <= kk && kk <= N-1)) {
                                dp[i][q][jj][kk] += dp[i-1][p][j][k];
                            }
                        }
                    }
                }
            } else {
                for (int p = 1; p <= N; ++p) for (int q = 1; q <= N; ++q) {
                    if (p > q) {
                        rep(k, N) rep(j, N) {
                            // q=p-1のときにj'はj-1になる。
                            // q=p-2のときにj'はj-2になる。
                            // q=p-zのときにj'はj-zになる。
                            int z = p-q;
                            int jj = j-z;
                            int whole = j+k-1;
                            int kk = whole-jj;
                            if ((0 <= jj && jj <= N-1) && (0 <= kk && kk <= N-1)) {
                                dp[i][q][jj][kk] += dp[i-1][p][j][k];
                            }
                        }
                    }
                }
            }
        }

        long ans = 0;
        for (int p = 1; p <= N; ++p) {
            ans = (ans + dp[N-1][p][0][0]) % MOD;
        }

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
