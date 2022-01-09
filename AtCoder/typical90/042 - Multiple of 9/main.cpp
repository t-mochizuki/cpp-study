// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::min;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

const int MOD = 1e9+7;

class Problem {
private:

    int K;
    vector<int> dp;

public:

    Problem() {
        cin >> K;

        dp.assign(K+1, 0);
        dp[0] = 1;
    }

    void solve() {
        if (K % 9 != 0) {
            cout << 0 << endl;
        } else {
            for (int i = 1; i <= K; ++i) {
                int B = min(i, 9);

                for (int j = 1; j <= B; ++j) {
                    dp[i] += dp[i-j];
                    dp[i] %= MOD;
                }
            }

            cout << dp[K] << endl;
        }
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
