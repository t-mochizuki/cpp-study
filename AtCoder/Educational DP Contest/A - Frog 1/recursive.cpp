// g++ -std=c++14 -DDEV=1 recursive.cpp
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
    }

    long cost(int from, int to) {
        return abs(h[to] - h[from]);
    }

    long rec(int i) {
        if (dp[i] != INF) return dp[i];

        if (i == 0) return 0;

        long res = INF;

        chmin(res, rec(i-1) + cost(i-1, i));

        if (i > 1) {
            chmin(res, rec(i-2) + cost(i-2, i));
        }

        return dp[i] = res;
    }

    void solve() {
        cout << rec(N-1) << endl;
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
