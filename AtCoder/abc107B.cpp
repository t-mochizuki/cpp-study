#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int H, W; cin >> H >> W;
    string a[H]; REP(0, i, H) cin >> a[i];

    // REP(0, i, H) cout << a[i] << endl;

    int h[H], w[W];
    REP(0, i, H) h[i] = 0;
    REP(0, i, W) w[i] = 0;

    REP(0, i, H) REP(0, j, W) {
        if (a[i][j] == '#') {
            // cout << i << ", " << j << endl;
            h[i] = 1;
            w[j] = 1;
        }
    }

    REP(0, i, H) {
        REP(0, j, W) {
            if (h[i] == 1 && w[j] == 1) {
                printf("%c", a[i][j]);
            }
        }
        if (h[i] == 1) printf("\n");
    }

    return 0;
}
