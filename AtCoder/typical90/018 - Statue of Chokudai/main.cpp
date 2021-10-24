// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)


class Problem {
private:

    const double pi = std::acos(-1.0);
    double T, L, X, Y;
    int Q;
    vector<double> E;

public:

    Problem() {
        cin >> T >> L >> X >> Y >> Q;

        E.resize(Q);
        rep(i, 0, Q) cin >> E[i];
    }

    void solve() {
        rep(i, 0, Q) {
            double theta = 2.0 * pi * (E[i] / T);
            double y = L/2.0 - (L/2.0) * cos(theta);
            assert(y >= 0);
            double x = sqrt(X*X + (Y-(-(L/2.0)*sin(theta)))*(Y-(-(L/2.0)*sin(theta))));
            assert(x >= 0);
            printf("%.8f\n", 180 * atan2(y, x) / pi);
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
