// g++ -std=c++14 -DDEV=1 push_based.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::abs;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)

const long INF = 1L << 30;

class Program {
private:

    int N;
    vector<long> h;
    vector<long> dp;

    template<class T> void chmin(T& a, T b) {
        if (a > b) {
            a = b;
        }
    }

public:
    Program() {
        cin >> N;

        h.resize(N);
        rep(i, 0, N) cin >> h[i];

        dp.assign(N, INF);
        dp[0] = 0;
    }

    long cost(int from, int to) {
        return abs(h[to] - h[from]);
    }

    void solve() {
        rep(i, 0, N) {
            if (i+1 < N) chmin(dp[i+1], dp[i] + cost(i, i+1));
            if (i+2 < N) chmin(dp[i+2], dp[i] + cost(i, i+2));
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
        Program p;
        p.solve();
    }
#else
    Program p;
    p.solve();
#endif

    return 0;
}
