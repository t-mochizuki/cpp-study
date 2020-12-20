#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve() {
    long h, w; cin >> h >> w;
    long wr = w % 2;
    long wq = w / 2;
    long hr = h % 2;
    long hq = h / 2;

    long ans = 0;
    if (h == 1 || w == 1) {
        ans = 1;
    } else if (wr == 1 && hr == 1) {
        ans = h * wq + hq + hr;
    } else if (wr == 1) {
        ans = h * wq + hq;
    } else if (hr == 1) {
        ans = h * wq;
    } else {
        ans = h * wq;
    }

    cout << ans << endl;
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
