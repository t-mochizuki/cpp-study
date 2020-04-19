#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

long latest(long x, long d) {
    // quotient
    long q = d / x;

    return x * q;
}

int main() {
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        int n; cin >> n;
        long d; cin >> d;
        long X[n];
        REP(0, i, n) cin >> X[i];

        long y;
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                y = latest(X[i], d);
            } else {
                y = latest(X[i], y);
            }
        }

        cout << "Case #" << x << ": " << y << endl;
    }

    return 0;
}
