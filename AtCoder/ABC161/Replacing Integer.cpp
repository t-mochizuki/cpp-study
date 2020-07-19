#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

template<class T> inline T abs(T X) {
    return X > 0 ? X : -X;
}

template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

void solve() {
    long n, k; cin >> n >> k;
    n %= k;
    long x = abs(n - k);
    cout << min(n, x) << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("AtCoder/ABC161/Replacing Integer.input");
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
