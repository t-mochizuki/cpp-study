#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int pow(int x, int n) {
    return n == 0 ? 1 : x * pow(x, n - 1);
}

int main() {
    int n, m; cin >> n >> m;

    // 派閥
    int w = pos(2, n);
    int b[w][n];
    // from 1 to 2^12-1
    for (int j = 1; j < w; ++j) {
        for (int i = 0; i < n; ++i) {
            b[j][i] = ((j >> i) & 0x1);
        }
    }

    // 隣接行列
    int a[n][n]
    REP(0, i, m) {
        int x, y; cin >> x >> y;
        x--; y--; // zero origin
        a[x][y] = 1;
        a[y][x] = 1;
    }

    int ans = 0;
    for (int j = 1; j < w; ++j) {
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                if (b[j][i] == 1 && a[i][k] == 1 && b[j][k] == 1) {
                }
            }
        }
    }

    return 0;
}
