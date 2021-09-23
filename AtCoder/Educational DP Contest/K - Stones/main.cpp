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

class Problem {
private:

    int N, K;
    vector<int> a;
    vector<bool> dp;

public:
    Problem() {
        cin >> N >> K;

        a.assign(N+1, 0);
        rep(i, N+1) {
            if (i == 0) continue;
            cin >> a[i];
        }

        // i個の石からなる山があるときに、先手が勝つかを求める。
        dp.resize(K+1, false);
    }

    void solve() {
        for (int i = 1; i <= K; ++i) for (int j = 1; j <= N; ++j) {
            if (i-a[j] >= 0 && dp[i-a[j]] == false) dp[i] = true;
        }

        cout << (dp[K] ? "First" : "Second") << endl;
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
