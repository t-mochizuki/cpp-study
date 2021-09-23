// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::abs;
using std::min;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class Problem {
private:

    int N;
    vector<int> h;
    vector<long> dp;

public:
    Problem() {
        cin >> N;

        h.assign(N, 0);
        rep(i, N) cin >> h[i];

        dp.assign(N, 0);
    }

    int cost(int i, int j) {
        return abs(h[i] - h[j]);
    }

    void solve() {
        rep(i, N) {
            if (i == 0) continue;
            if (i == 1) dp[i] = cost(i - 1, i) + dp[i - 1];
            else dp[i] = min(cost(i - 1, i) + dp[i - 1], cost(i - 2, i) + dp[i - 2]);
        }

        cout << dp[N - 1] << endl;
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
