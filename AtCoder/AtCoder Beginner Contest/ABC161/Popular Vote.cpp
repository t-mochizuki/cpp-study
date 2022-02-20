#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve() {
    int n, m; cin >> n >> m;
    int a[n];
    int all = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        all += a[i];
        a[i] *= 4 * m;
    }

    int y = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= all) {
            y++;
        }
    }

    cout << (y >= m ? "Yes" : "No") << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("AtCoder/ABC161/Popular Vote.input");
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
