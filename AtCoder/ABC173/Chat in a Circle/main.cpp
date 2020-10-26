#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::map;
using std::make_pair;
using std::sort;
using std::greater;

void solve() {
    int n; cin >> n;
    long a[n];
    for (int x = 0; x < n; ++x) {
        cin >> a[x];
    }

    if (n < 2) {
        cout << 0 << endl;
        return ;
    }

    sort(a, a + n, greater<long>());

    // for (auto v : a) {
    //     cout << v << endl;
    // }

    long ans = 0;
    for (int x = 0; x < n - 1; ++x) {
        ans += a[(x + 1) / 2];
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
