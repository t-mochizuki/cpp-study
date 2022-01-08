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
using std::max;
using std::min;
using std::abs;

// キーワード: マンハッタン距離は45度回転

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Point {
public:

    long x;
    long y;

    Point() {
        cin >> x >> y;
        assert(x >= -1000000000);
        assert(x <= 1000000000);
        assert(y >= -1000000000);
        assert(y <= 1000000000);

        rotate45();
    }

    void rotate45() {
        long X = x-y;
        long Y = x+y;

        x = X;
        y = Y;
    }
};

class Problem {
private:

    int N, Q;
    vector<Point> P;

public:

    Problem() {
        cin >> N >> Q;
        assert(N >= 2);
        assert(N <= 100000);
        assert(Q >= 1);
        assert(Q <= N);

        P.resize(N);
    }

    void solve() {
        long xmin = 1000000000, xmax = -1000000000, ymin = 1000000000, ymax = -1000000000;
        rep(i, 0, N) {
            xmin = min(P[i].x, xmin);
            ymin = min(P[i].y, ymin);
            xmax = max(P[i].x, xmax);
            ymax = max(P[i].y, ymax);
        }

        rep(i, 0, Q) {
            int q; cin >> q; q--;

            long ans = 0;
            ans = max(abs(P[q].x - xmin), ans);
            ans = max(abs(P[q].x - xmax), ans);
            ans = max(abs(P[q].y - ymin), ans);
            ans = max(abs(P[q].y - ymax), ans);

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
        Problem p;
        p.solve();
    }
#else
    Problem p;
    p.solve();
#endif

    return 0;
}
