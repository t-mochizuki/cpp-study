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
using std::min;

// キーワード: 列の操作は区間DP

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int N;
    vector<int> A;
    // dp[l][r]: l, l+1, ..., r番目の数を取り除く最小コストを求める
    vector<vector<int>> dp;

    void debug_A() {
        for (int i = 1; i <= 2*N; ++i) {
            if (i == 1) cout << A[i];
            else cout << " " << A[i];
        }
        cout << endl;
    }

    void debug() {
        for (int l = 1; l <= 2*N; ++l) {
            for (int r = 1; r <= 2*N; ++r) {
                if (r == 1) cout << dp[l][r];
                else cout << " " << dp[l][r];
            }
            cout << endl;
        }
        cout << endl;
    }

public:

    Problem() {
        cin >> N;

        A.resize(2*N+1);
        for (int i = 1; i <= 2*N; ++i) cin >> A[i];

        dp.assign(2*N+1, vector<int>(2*N+1, 1<<29));
        for (int i = 1; i <= 2*N-1; ++i) {
            dp[i][i+1] = abs(A[i]-A[i+1]);
        }
    }

    void solve() {
        for (int i = 3; i <= 2*N; i += 2) {
            for (int l = 1; l <= 2*N; ++l) {
                int r = l + i;

                if (r <= 2*N) {
                    for (int k = l; k <= r-1; ++k) {
                        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
                    }

                    dp[l][r] = min(dp[l][r], dp[l+1][r-1] + abs(A[l]-A[r]));
                }
            }
        }

        // debug();

        cout << dp[1][2*N] << endl;
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
