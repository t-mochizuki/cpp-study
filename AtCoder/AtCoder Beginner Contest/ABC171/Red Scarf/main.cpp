#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve() {
    int n; cin >> n;
    int a[n];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans = ans ^ a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
            cout << (ans ^ a[i]) << endl;
        } else {
            cout << (ans ^ a[i]) << " ";
        }
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
