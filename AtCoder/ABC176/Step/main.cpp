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
using std::to_string;
using std::lower_bound;
using std::distance;

void solve() {
    int n; cin >> n;
    long a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long ans = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i-1] > a[i]) {
            ans += a[i-1] - a[i];
            a[i] = a[i-1];
        }
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
