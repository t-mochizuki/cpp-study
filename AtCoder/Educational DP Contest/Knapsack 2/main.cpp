// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::min;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const long INF = 1e9 + 1;

class Problem {
private:

    long N; // 1 <= N <= 100
    long W; // 1 <= W <= 1e9
    vector<long> w; // 1 <= w <= W
    vector<long> v; // 1 <= v <= 1e3
    vector<vector<long> > dp;

public:
    Problem() {
        cin >> N >> W;

        w.assign(N+1, INF);
        v.assign(N+1, 0);
        rep(i, N+1) {
            if (i == 0) continue;
            cin >> w[i] >> v[i];
        }

        dp.assign(N+1, vector<long>(100001, INF));
    }

    void solve() {
        rep(i, N+1) {
            rep(j, 100001) {
                if (i == 0 || j == 0) {
                    dp[i][j] = INF;
                    continue;
                }
                // dp[i][j] = min(dp[i-1][j], min(j <= v[i] ? w[i] : INF, w[i] + dp[i-1][j - v[i]]));
                if (j <= v[i]) {
                    dp[i][j] = w[i];
                } else {
                    dp[i][j] = w[i] + dp[i-1][j - v[i]];
                }
                dp[i][j] = min(dp[i-1][j], dp[i][j]);
            }
        }

        // rep(i, N+1) {
        //     rep(j, 28) {
        //         if (j == 0) 
        //             cout << (dp[i][j] == INF ? "INF" : std::to_string(dp[i][j]));
        //         else
        //             cout << " " << (dp[i][j] == INF ? "INF" : std::to_string(dp[i][j]));
        //     }
        //     cout << endl;
        // }

        int ans = 0;
        rep(j, 100001) {
            if (dp[N][j] <= W) {
                ans = max(j, ans);
            }
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
