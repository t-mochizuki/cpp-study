#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

long floor(long x, long y) {
     return x / y;
}

long expr(long A, long B, long x) {
    return floor(A * x, B) - A * floor(x, B);
}

void solve() {
    long A, B, N; cin >> A >> B >> N;
    long ans = 0;
    if (N < B) {
        ans = expr(A, B, N);
    } else {
        ans = expr(A, B, B - 1 > 0 ? B - 1 : 1);
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
