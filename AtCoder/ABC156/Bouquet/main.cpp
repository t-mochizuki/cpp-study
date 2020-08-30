#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

template<class T> inline T pow(T base, T exponent, T mod) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return base * pow(base, exponent - 1, mod) % mod;
    } else {
        T tmp = pow(base, exponent / 2, mod);
        return (tmp * tmp) % mod;
    }
}

void solve() {
    long n, a, b; cin >> n >> a >> b;
    long mod = 1e9 + 7;

    long ans = pow(2l, n, mod) - 1;

    long X = 1;
    for (int i = n; i >= n - (a - 1); --i) {
        X *= i;
        X %= mod;
    }

    long Y = 1;
    for (int i = 1; i <= a; ++i) {
        Y *= i;
        Y %= mod;
    }

    ans += mod;
    ans -= X * pow(Y, mod - 2, mod) % mod;

    X = 1;
    for (int i = n; i >= n - (b - 1); --i) {
        X *= i;
        X %= mod;
    }

    Y = 1;
    for (int i = 1; i <= b; ++i) {
        Y *= i;
        Y %= mod;
    }

    ans += mod;
    ans -= X * pow(Y, mod - 2, mod) % mod;

    cout << ans % mod << endl;
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
