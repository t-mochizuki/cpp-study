#include <stdio.h>
#include <iostream>
// #include <fstream>

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
    if (d > x * y) return 0;
    if (l > (x * y - d)) return 0;
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

    if (x * y == d + l) {
    } else {
        // A: XY領域のもっとも上の行を使っていない
        long tmp = func(x - 1, y, d, l);
        // B: XY領域のもっとも左の列を使っていない
        tmp += func(x, y - 1, d, l);
        // C: XY領域のもっとも下の行を使っていない
        tmp += func(x - 1, y, d, l);
        // D: XY領域のもっとも右の列を使っていない
        tmp += func(x, y - 1, d, l);

        // A かつ B
        tmp -= func(x - 1, y - 1, d, l);
        // A かつ C
        tmp -= func(x - 2, y, d, l);
        // A かつ D
        tmp -= func(x - 1, y - 1, d, l);
        // B かつ C
        tmp -= func(x - 1, y - 1, d, l);
        // B かつ D
        tmp -= func(x, y - 2, d, l);
        // C かつ D
        tmp -= func(x - 1, y - 1, d, l);

        // A かつ B かつ C
        tmp += func(x - 2, y - 1, d, l);
        // A かつ B かつ D
        tmp += func(x - 1, y - 2, d, l);
        // A かつ C かつ D
        tmp += func(x - 2, y - 1, d, l);
        // B かつ C かつ D
        tmp += func(x - 1, y - 2, d, l);

        // A かつ B かつ C かつ D
        tmp -= func(x - 2, y - 2, d, l);

        ans -= tmp;
        ans += MOD * 7;
    }

    cout << (w * ans) % MOD << endl;
}

int main() {
    // std::ifstream in("AtCoder/ABC003/AtCoder社の冬.input");
    // cin.rdbuf(in.rdbuf());

    // int t; cin >> t;
    // for (int x = 1; x <= t; ++x) {
    //     solve();
    // }

    solve();

    return 0;
}
