#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

const long MOD = 1000000007;

void solve() {
    int S; cin >> S;
    long a[S+1];
    a[0] = 1;
    a[1] = 0;
    a[2] = 0;

    long tmp = a[0];
    for (int i = 3; i <= S; ++i) {
        a[i] = 0;
        a[i] = tmp;
        tmp += a[i - 2];
        tmp %= MOD;
    }

    cout << a[S] << endl;
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
