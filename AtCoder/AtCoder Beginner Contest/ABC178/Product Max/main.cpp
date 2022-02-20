#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

void solve() {
    long a, b, c, d; cin >> a >> b >> c >> d;
    cout << max(max(a*c, a*d), max(b*c, b*d)) << endl;
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
