#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int n; cin >> n;
    int d[n + 1][n + 1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> d[i][j];
        }
    }
    int q; cin >> q;
    int p[q + 1];
    for (int i = 1; i <= q + 1; ++i) {
        cin >> p[i];
    }

    // 右下のおいしさの合計
    int total[n + 1][n + 1];
    for (int j = n; j > 0; ++j) {
        for (int i = n; i > 0; ++i) {
            if (j == n && i == n) {
                total[n][n] = d[n][n];
            } else if (j == n) {
                total[i][n] = d[i][n] + total[i + 1][n];
            } else if (i == n) {
                total[n][j] = d[n][j] + total[n][j + 1];
            } else {
                total[i][j] = d[i][j] + total[i + 1][j] + total[i][j + 1] - total[i + 1][j + 1];
            }
        }
    }

    // さまざまな長方形
    for (int li = 1; li <= n; ++li) {
        for (int lj = 1; lj <= n; ++lj) {
            for (int ri = li; ri <= n; ++ri) {
                for (int rj = lj; rj <= n; ++rj) {
                }
            }
        }
    }

    return 0;
}
