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
    int k, n; cin >> k >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int b = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            b = max(b, a[i] + (k - a[n - 1]));
        } else {
            b = max(b, a[i] - a[i - 1]);
        }
    }

    cout << k - b << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("AtCoder/ABC160/Traveling Salesman around Lake.input");
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
