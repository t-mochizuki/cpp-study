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

#define rep(i, a, n) for (int i = a; i < (n); ++i)

const long MOD = 1e9 + 7;

class Problem {
private:

    int N;
    string s;
    // 集合{1,2,...,N}から元を選んで順列Pを作る。
    // 文字列sのi番目まで条件を満たすときに、順列Pのi+1番目の値が決まる。
    // この値P_i+1より小さい値をもつ元であり、まだ選ばれていない値をもつ元がj個あるとする。
    // この値P_i+1より大きい値をもつ元であり、まだ選ばれていない値をもつ元がk個あるとする。
    // そのときに条件を満たす順列が何通りかを求める。
    vector<vector<long>> dp;

public:
    Problem() {
        cin >> N >> s;

        s = " " + s;

        if (N > 500) {
            terminate();
        }

        dp.assign(N, vector<long>(N, 0));
    }

    void solve() {

        rep(p, 1, N+1) {
            dp[0]/*[p]*/[p-1]/*[N-p]*/ = 1;
        }

        rep(i, 1, N) {
            if (s[i] == '<') {
                // z = q-p;
                // N-i = j+k
                rep(z, 1, N-i+1) {
                    for (int j = N-i-z; j >= 0; --j) {
                        int k = (N-i)-j;
                        int kk = k-z;
                        int whole = N-i-1;
                        int jj = whole-kk;
                        dp[i]/*[q]*/[jj]/*[kk]*/ += dp[i-1]/*[p]*/[j]/*[k]*/;
                    }
                }
            } else {
                // z = p-q;
                // N-i = j+k
                rep(z, 1, N-i+1) {
                    rep(j, z, N-i+1) {
                        int jj = j-z;
                        int whole = N-i-1;
                        int kk = whole-jj;
                        dp[i]/*[q]*/[jj]/*[kk]*/ += dp[i-1]/*[p]*/[j]/*[k]*/;
                    }
                }
            }
        }

        long ans = dp[N-1][0] % MOD;

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
