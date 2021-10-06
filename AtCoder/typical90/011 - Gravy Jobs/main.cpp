// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::sort;
using std::max;

// キーワード: 仕事は締切の早い順に

// キーワード: ソート順にDP

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Job {
private:

public:
    int D, C, S;

    Job() {
        cin >> D >> C >> S;
    }

    void debug() {
        cout << D << "," << C << "," << S << endl;
    }

    bool operator<(const Job& that) const {
        return D < that.D;
    }
};

class Problem {
private:
    int N;
    int D = 0;
    vector<Job> xs;
    vector<vector<long>> dp;

public:
    Problem() {
        cin >> N;

        rep(i, 0, N) {
            xs.push_back(Job());
            D = max(D, xs[i].D);
        }

        dp.assign(N+1, vector<long>(D+1, 0));
    }

    void debug() {
        for (auto x : xs) {
            x.debug();
        }
    }

    void debug_dp() {
        rep(i, 1, N+1) {
            rep(j, 0, D+1) {
                if (j == 0) cout << dp[i][j];
                else cout << "," << dp[i][j];
            }
            cout << endl;
        }
    }

    void fullSearch() {
        sort(xs.begin(), xs.end());

        long y = 0;
        for (int /*bit*/ pat/*tern*/ = (1<<N)-1; pat >= 0; --pat) {
            int day = 1;
            long score = 0;
            rep(i, 0, N) {
                auto x = xs[i];
                if (bit(pat, i) == 1) {
                    if (day+x.C-1 <= x.D) {
                        day += x.C;
                        score += x.S;
                    }
                }
            }
            y = max(y, score);
        }

        cout << y << endl;
    }

    void solve() {
        sort(xs.begin(), xs.end());

        rep(i, 1, N+1) rep(j, 0, D+1) {
            if (j < xs[i-1].C || xs[i-1].D < j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j-xs[i-1].C > 0 ? j-xs[i-1].C : 0] + xs[i-1].S, dp[i-1][j]);
            }
        }

        long y = 0;
        rep(j, 0, D+1) {
            y = max(y, dp[N][j]);
        }

        cout << y << endl;
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
