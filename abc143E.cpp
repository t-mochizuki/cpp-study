// I read the submission #8087563.
#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int main() {
    int n, m, l; cin >> n >> m >> l;
    int d[n][n];
    REP(0, i, n) {
        REP(0, j, n) {
            d[i][j] = 1000000007;
        }
        d[i][i] = 0;
    }
    int a[m], b[m], c[m];
    REP(0, i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        d[a[i]][b[i]] = min(d[a[i]][b[i]], c[i]);
        d[b[i]][a[i]] = min(d[b[i]][a[i]], c[i]);
    }
    REP(0, k, n) {
        REP(0, i, n) {
            REP(0, j, n) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    REP(0, i, n) {
        REP(0, j, n) {
            if (d[i][j] == 0) d[i][j] = 0;
            else if (d[i][j] <= l) d[i][j] = 1;
            else d[i][j] = 1000000007;
        }
    }
    REP(0, k, n) {
        REP(0, i, n) {
            REP(0, j, n) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int q; cin >> q;
    REP(0, i, q) {
        int s, t; cin >> s >> t; s--; t--;
        if (d[s][t] == 1000000007) cout << "-1" << endl;
        else cout << d[s][t] - 1 << endl;
    }
    return 0;
}
