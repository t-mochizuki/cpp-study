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
                // zz = j+z-1
                // j=N-1のときにz=1となるp,qの対はp=N,q=N+1である。
                // j=N-2のときにz=2となるp,qの対はp=N,q=N+2. p=N-1,q=N+1である。
                // j=N-3のときにz=3となるp,qの対はp=N,q=N+3. p=N-1,q=N+2. p=N-2,q=N+1である。
                // これらは条件を満たさないので取り除く。
                rep(zz, 0, N-i) rep(j, 0, zz+1) {
                    dp[i]/*[q]*/[zz]/*[kk]*/ += dp[i-1]/*[p]*/[j]/*[k]*/;
                }
            } else {
                // z = p-q;
                // N-i = j+k
                // zz = j-z
                rep(zz, 0, N-i) rep(j, zz+1, N-i+1) {
                    dp[i]/*[q]*/[zz]/*[kk]*/ += dp[i-1]/*[p]*/[j]/*[k]*/;
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
