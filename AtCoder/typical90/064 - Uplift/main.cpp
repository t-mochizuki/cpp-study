// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::string;
using std::pair;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::abs;
using std::sort;

// キーワード: 階差(隣り合う2つの要素の差)を考えよう

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

    long n, q, ans = 0;
    vector<long> a, b;

public:

    Program() {
        cin >> n >> q;

        a.resize(n);
        rep(i, 0, n) cin >> a[i];

        b.assign(n+5, 0);
        rep(i, 1, n) {
            b[i] = a[i] - a[i-1];
        }

        rep(i, 1, n) {
            ans += abs(b[i]);
        }

    }

    void solve() {

        rep(i, 0, q) {
            long L, R, V; cin >> L >> R >> V;
            // cout << "L:" << L << "," << "R:" << R << endl;

            // 地殻変動の前
            long before = abs(b[L-1]) + abs(b[R]);

            if (L >= 2) b[L-1] += V;
            if (R <= n-1) b[R] -= V;

            // 地殻変動の後
            long after = abs(b[L-1]) + abs(b[R]);

            ans += (after - before);
            cout << ans << endl;
        }
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
