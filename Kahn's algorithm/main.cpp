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
    vector<vector<int>> E;
    vector<vector<int>> B;

    vector<int> L; // Empty list that will contain the sorted elements.
    stack<int> S; // Stack of all nodes with no incoming edge.

public:
    Problem() {
        cin >> N >> M;

        E.assign(N, vector<int>());
        B.assign(N, vector<int>());
        rep(i, M) {
            int x, y;
            cin >> x >> y;
            x--; y--;

            E[x].push_back(y);
            B[y].push_back(x);
        }

        rep(startNode, N) {
            if (B[startNode].empty()) {
                S.push(startNode);
            }
        }
    }

    void debug() {
        bool first = true;
        for (const auto& x : L) {
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

            auto ys = E[x]; E[x].clear();
            for (const auto& y : ys) {
                for (auto it = B[y].begin(); it != B[y].end();) {
                    if (*it == x) {
                        it = B[y].erase(it);
                        break;
                    } else {
                        ++it;
                    }
                }

                if (B[y].empty()) {
                    S.push(y);
                }
            }
        }

        debug();
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
