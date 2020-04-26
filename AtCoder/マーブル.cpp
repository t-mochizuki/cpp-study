#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int r, g, b; cin >> r >> g >> b;
    r--, g--, b--;

    int ans, w; ans = 0; w = 1;
    REP(0, i, r) {
        if (i % 2 == 0 && i != 0) {
            w++;
        }
        ans += w;
    }
    w = 1;
    REP(0, i, g) {
        if (i % 2 == 0 && i != 0) {
            w++;
        }
        ans += w;
    }
    w = 1;
    REP(0, i, b) {
        if (i % 2 == 0 && i != 0) {
            w++;
        }
        ans += w;
    }

    cout << ans << endl;
    return 0;
}
