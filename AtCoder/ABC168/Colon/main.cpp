#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve() {
    int b, c;
    int h; // 0 <= h <= 11
    int m; // 0 <= m <= 59
    cin >> b >> c >> h >> m;

    // 余弦定理
    // cosα=(b^2 + c^2 - a^2) / 2bc
    // a^2=b^2 + c^2 - 2bc cosα

    long double hh = h * (2*M_PI / 12) + m * (2*M_PI / 12 / 60);
    long double mm = m * (2*M_PI / 60);
    long double r = hh-mm;

    printf("%20.20Lf\n", sqrtl(b*b+c*c-2*b*c*cosl(r)));
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
