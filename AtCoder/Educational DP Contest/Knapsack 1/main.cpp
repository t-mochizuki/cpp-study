// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class Problem {
private:

    int N; // 1 <= N <= 100
    int W; // 1 <= W <= 1e5
    vector<int> w; // 1 <= w <= W
    vector<int> v; // 1 <= v <= 1e9
    vector<vector<long> > dp;

public:
    Problem() {
        cin >> N >> W;

        w.assign(N+1, 0);
        v.assign(N+1, 0);
        rep(i, N+1) {
            if (i == 0) continue;
            cin >> w[i] >> v[i];
        }

        dp.assign(N+1, vector<long>(W+1, 0));
    }

    void solve() {
        rep(i, N+1) rep(j, W+1) {
            if (i == 0 || j == 0) continue;

            dp[i][j] = j >= w[i] ? v[i] : 0;

            if (j >= w[i]) {
                dp[i][j] = v[i] + dp[i-1][j-w[i]];
            }

            dp[i][j] = max(dp[i-1][j], dp[i][j]);
        }

        cout << dp[N][W] << endl;
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
