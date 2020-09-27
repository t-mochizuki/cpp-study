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
    int h[n], tmp[n];
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        tmp[i] = 1;
    }

    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; a--; b--;
        if (h[a] == h[b]) {
            tmp[a] = 0;
            tmp[b] = 0;
        } else if (h[a] > h[b]) {
            tmp[b] = 0;
        } else if (h[a] < h[b]) {
            tmp[a] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += tmp[i];
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
