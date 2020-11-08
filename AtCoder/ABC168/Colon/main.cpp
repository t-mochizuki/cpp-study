#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

// TODO: WA

const double pi = 2.0 * asin(1.0);
const double radian = pi / 180.0;

void solve() {
    int b, c;
    int h; // 0 <= h <= 11
    int m; // 0 <= m <= 59
    cin >> b >> c >> h >> m;

    // 余弦定理
    // cosα=(b^2 + c^2 - a^2) / 2bc
    // a^2=b^2 + c^2 - 2bc cosα

    double hh = h * (360.0 / 12);
    double mm = m * (360.0 / 60);
    double r;
    if (hh>mm) r=hh-mm;
    else r=mm-hh;
    if (r > 180) r-=180;
    r*=radian;

    double ans = sqrt(b*b+c*c-2*b*c*cos(r));
    printf("%.15g\n", ans);
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
