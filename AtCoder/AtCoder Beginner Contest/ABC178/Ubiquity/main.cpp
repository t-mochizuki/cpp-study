#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

const long p = 1000000007;

template<class T> inline T pow(T base, T exponent) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return (base * pow(base, exponent - 1)) % p;
    } else {
        T tmp = pow(base, exponent / 2);
        return (tmp * tmp) % p;
    }
}

void solve() {
    long N; cin >> N;

    if (N == 1) {
        cout << 0 << endl;
        return ;
    }

    long ans = pow(10L, N) - 2 * pow(9L, N) + pow(8L, N);

    ans %= p;
    ans = (ans + p) % p;
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
