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
using std::string;
using std::vector;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class Problem {
private:

    int N;
    vector<double> p;
    vector<vector<double>> dp;

public:
    Problem() {
        cin >> N;

        p.assign(N+1, 0.0);
        rep(i, N+1) {
            if (i == 0) continue;
            cin >> p[i];
        }

        // コイン1からコインiまで投げたときに、j枚が表である確率を求める。
        dp.assign(N+1, vector<double>(N+1, 0.0));
        dp[0][0] = 1.0;
    }

    void solve() {

        rep(i, N+1) rep(j, i+1) {
            if (i == 0) continue;
            if (j == 0) dp[i][j] = dp[i-1][j] * (1 - p[i]);
            else dp[i][j] = dp[i-1][j] * (1 - p[i]) + dp[i-1][j-1] * p[i];
        }

        double ans = 0.0;
        for (int j = N/2 + 1; j <= N; ++j) ans += dp[N][j];
        printf("%.10lf\n", ans);
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
