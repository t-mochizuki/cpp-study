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

#define rep(i, n) for (int i = 0; i < (n); ++i)

const long MOD = 1e9 + 7;

class Problem {
private:

    int N;
    vector<vector<int>> E;
    vector<bool> visited;
    vector<vector<long>> dp;

public:
    Problem() {
        cin >> N;

        E.assign(N, vector<int>());
        rep(i, N-1) {
            int x, y; cin >> x >> y;
            x--; y--;
            E[x].push_back(y);
            E[y].push_back(x);
        }

        visited.assign(N, false);

        dp.assign(N, vector<long>(2, 0));
    }

    void rec(int from, int parent) {
        if (visited[from]) return;
        visited[from] = true;

        dp[from][0] = 1;
        dp[from][1] = 1;
        for (auto to : E[from]) {
            if (to == parent) continue;

            rec(to, from);

            dp[from][0] *= dp[to][0] + dp[to][1];
            dp[from][0] %= MOD;

            dp[from][1] *= dp[to][0];
            dp[from][1] %= MOD;
        }
    }

    void solve() {
        rec(0, -1);
        cout << ((dp[0][0] + dp[0][1] + MOD) % MOD) << endl;
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
