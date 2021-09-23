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
using std::max;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int N;
    vector<vector<int>> a;
    vector<long> dp;
    vector<long> score;

public:
    Problem() {
        cin >> N;

        a.resize(N, vector<int>(N, 0));
        rep(i, 0, N) rep(j, 0, N) cin >> a[i][j];

        dp.assign(1<<N, 0);

        score.assign(1<<N, 0);
        rep(S, 0, 1<<N) {
            rep(i, 0, N) rep(j, i + 1, N) {
                if (bit(S, i) && bit(S, j)) score[S] += a[i][j];
            }
        }
    }

    void solve() {
        rep(S, 0, 1<<N) {
            for (int T = S; T > 0; T = (T - 1) & S) {
                long tmp = dp[S - T] + score[T];
                dp[S] = max(dp[S], tmp);
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
