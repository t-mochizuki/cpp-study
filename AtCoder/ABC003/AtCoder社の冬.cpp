#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

long memo[901][901];

long pascal(long i, long j) {
    if (memo[i][j] != 0) return memo[i][j];

    memo[i][j] = (pascal(i - 1, j - 1) + pascal(i - 1, j)) % 1000000007;

    return memo[i][j];
}

int main() {
    int r, c; cin >> r >> c;
    int x, y; cin >> x >> y;
    int d, l; cin >> d >> l;

    REP(0, i, 901) REP(0, j, 901) {
        if (i == j || j == 0) {
            memo[i][j] = 1;
        } else {
            memo[i][j] = 0;
        }
    }

    int rx = r - x + 1;
    int cy = c - y + 1;
    int w = rx * cy;

    cout << (w * pascal(d + l, d)) % 1000000007 << endl;

    return 0;
}
