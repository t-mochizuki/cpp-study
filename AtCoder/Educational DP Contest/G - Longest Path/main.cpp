// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::max;
using std::stack;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class Problem {
private:

    int N, M;
    vector<vector<int>> E; // adjacency list
    vector<int> incoming;

    vector<int> L; // Empty list that will contain the sorted elements.
    stack<int> S; // Stack of all nodes with no incoming edge.

    vector<int> dp;

public:
    Problem() {
        cin >> N >> M;

        E.assign(N, vector<int>(0));
        incoming.assign(N, 0);
        rep(i, M) {
            int x, y;
            cin >> x >> y;
            x--; y--;

            E[x].push_back(y);
            incoming[y]++;
        }

        rep(startNode, N) {
            if (incoming.at(startNode) == 0) {
                S.push(startNode);
            }
        }

        dp.assign(N, 0);
    }

    void debug() {
        bool first = true;
        for (const auto& x : dp) {
            if (first) {
                first = false;
                cout << x;
            } else {
                cout << " " << x;
            }
        }
        cout << endl;
    }

    void solve() {
        while (!S.empty()) {
            int x = S.top(); S.pop();
            L.push_back(x);

            const auto& ys = E[x];
            for (const auto& y : ys) {
                incoming[y]--;

                if (incoming[y] == 0) {
                    S.push(y);
                }
            }
        }

        for (const auto& from : L) {
            for (const auto& to : E[from]) {
                dp[to] = max(dp[to], dp[from] + 1);
            }
        }

        int ans = 0;
        rep(i, N) ans = max(ans, dp[i]);
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
