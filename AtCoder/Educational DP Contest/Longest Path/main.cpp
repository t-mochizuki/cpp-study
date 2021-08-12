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

#define rep(i, n) for (int i = 0; i < (n); ++i)

class Problem {
private:

    int n, m;
    vector<vector<int>> E;
    vector<vector<int>> B;
    vector<int> dp;

public:
    Problem() {
        cin >> n >> m;

        E.assign(n, vector<int>());
        B.assign(n, vector<int>());
        rep(i, m) {
            int x, y;
            cin >> x >> y;
            x--; y--;

            E[x].push_back(y);
            B[y].push_back(x);
        }

        dp.assign(n, -1);
    }

    void debug() {
        for (const auto& x : dp) cout << x << endl;
    }

    int rec(int from) {
        if (dp[from] != -1) return dp[from];

        int ret = 0;
        for (auto to : E[from]) {
            ret = max(rec(to) + 1, ret);
        }
        return dp[from] = ret;
    }

    void solve() {
        rep(startNode, n) {
            if (B[startNode].empty()) {
                rec(startNode);
            }
        }

        int ans = 0;
        rep(i, n) {
            ans = max(dp[i], ans);
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
