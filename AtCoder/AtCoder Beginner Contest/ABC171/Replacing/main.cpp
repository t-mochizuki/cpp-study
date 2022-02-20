#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve() {
    long n; cin >> n;
    long ans = 0;
    long a[n];
    long v[100005] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i];
        v[a[i]]++;
    }

    long q; cin >> q;
    for (int i = 0; i < q; ++i) {
        long b, c; cin >> b >> c;
        ans -= b * v[b];
        ans += c * v[b];

        cout << ans << endl;

        long tmp = v[b];
        v[b] = 0;
        v[c] += tmp;
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
