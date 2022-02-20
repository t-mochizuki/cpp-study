// g++ -std=c++14 -DDEV=1 -Wall main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

void solve() {
    long N, A, B; cin >> N >> A >> B;
    long X[N];
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    long ans = 0;
    for (int i = 0; i < N-1; ++i) {
        long D = X[i+1] - X[i];
        ans += (B > A * D) ? A * D : B;
    }

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
