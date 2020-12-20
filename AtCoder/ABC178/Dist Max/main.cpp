#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

void solve() {
    int n; cin >> n;
    long x[n], y[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i]; cin >> y[i];
    }
    long z[n], w[n], zmin, zmax, wmin, wmax;
    for (int i = 0; i < n; ++i) {
        z[i] = x[i] + y[i];
        w[i] = x[i] - y[i];
        if (i == 0) {
            zmin = z[i];
            zmax = z[i];
            wmin = w[i];
            wmax = w[i];
        } else {
            zmin = min(zmin, z[i]);
            zmax = max(zmax, z[i]);
            wmin = min(wmin, w[i]);
            wmax = max(wmax, w[i]);
        }
    }

    cout << max(zmax - zmin, wmax - wmin) << endl;

}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
