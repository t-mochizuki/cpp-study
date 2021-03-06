#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve() {
    long a, b, c; cin >> a >> b >> c;
    if (a > c || b > c) {
        cout << "No" << endl;
        return ;
    }

    if (4 * a * b < (c - a - b) * (c - a - b)) {
            cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
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
