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

    int N;
    vector<int> h;
    vector<int> a;
    vector<long> dp;

public:
    Problem() {
        cin >> N;

        h.resize(N);
        rep(i, N) cin >> h[i];

        a.resize(N);
        rep(i, N) cin >> a[i];

        dp.assign(N+1, 0);
    }

    void print() {
        bool first = true;
        for (auto x : dp) {
            if (first) {
                cout << x;
                first = false;
            } else {
                cout << " " << x;
            }
        }
        cout << endl;
    }

    void solve() {
        rep(i, N) {
            long tmp = 0;
            rep(j, h[i]) {
                tmp = max(dp[j], tmp);
            }
            dp[h[i]] = tmp + a[i];
        }

        long ans = 0;
        rep(i, N+1) {
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
