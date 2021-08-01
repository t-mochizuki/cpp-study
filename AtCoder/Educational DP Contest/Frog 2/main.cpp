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

const int INF = 1e9;

class Problem {
private:

    int N, K;
    vector<int> h;
    vector<long> dp;

public:
    Problem() {
        cin >> N >> K;

        h.assign(N, 0);
        rep(i, N) cin >> h[i];

        dp.assign(N, INF);
    }

    int cost(int i, int j) {
        return abs(h[i] - h[j]);
    }

    void solve() {
        rep(i, N) {
            if (i == 0) dp[i] = 0;;
            rep(k, K) {
                if (i - k - 1 < 0) continue;
                dp[i] = min(cost(i - k - 1, i) + dp[i - k - 1], dp[i]);
            }
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
