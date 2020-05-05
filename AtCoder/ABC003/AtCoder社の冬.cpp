#include <stdio.h>
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

#define REP(a, i, n) for (int i = a; i < n; ++i)

const long MOD = 1000000007;
long memo[901][901];

long pascal(long i, long j) {
    if (memo[i][j] != 0) return memo[i][j];

    memo[i][j] = (pascal(i - 1, j - 1) + pascal(i - 1, j)) % MOD;

    return memo[i][j];
}

long func(long x, long y, long d, long l) {
    if (x < 0 || y < 0) return 0;
    return pascal(x * y, d) * pascal(x * y - d, l) % MOD;
}

void solve() {
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

    long ans = func(x, y, d, l);

    cout << (w * ans) % MOD << endl;
}

int main() {
    std::ifstream in("AtCoder/ABC003/AtCoder社の冬.input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }

    return 0;
}
