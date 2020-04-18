#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

double f(double a, double b, double c) {
    if (c > M_PI / 2.0 - 0.0000001) {
        return 0.0;
    }
    if (a * tan(c) <= b) {
        return a * a * b - a * a * a * tan(c) / 2.0;
    } else {
        return b * b / tan(c) * a / 2.0;
    }
}

int main() {
    double a, b, x; cin >> a >> b >> x;

    double ok = M_PI / 2.0;
    double ng = 0.0;
    REP(0, i, 100000) {
        double mid = (ok + ng) / 2.0;
        if (f(a, b, mid) < x) ok = mid;
        else ng = mid;
    }

    printf("%.7f\n", ok * 90.0 / (M_PI / 2.0));

    return 0;
}
