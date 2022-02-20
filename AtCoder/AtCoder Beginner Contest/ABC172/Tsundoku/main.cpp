#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::map;
using std::make_pair;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int a[n];
    for (int x = 0; x < n; ++x) { cin >> a[x]; }
    int b[m];
    for (int x = 0; x < m; ++x) { cin >> b[x]; }
    int ia = -1;
    for (int x = 0; x < n; ++x) {
        if (k >= a[x]) {
            k -= a[x];
            ia = x;
        } else {
            break;
        }
    }

    int ans = ia + 1;

    int ib = -1;
    for (int x = 0; x < m; ++x) {
        if (k >= b[x]) {
            k -= b[x];
            ib = x;
        } else {
            bool ng = true;
            for (; ia >= 0;) {
                k += a[ia];
                ia--;
                if (k >= b[x]) {
                    k -= b[x];
                    ib = x;
                    ng = false;
                    break;
                }
            }
            if (ng) break;
        }

        // cout << ia + 1 + ib + 1 << endl;
        ans = max(ans, ia + 1 + ib + 1);
        // cout << "ans:" << ans << endl;
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
