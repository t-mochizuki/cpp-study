#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <set>

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
using std::deque;
using std::set;

void solve() {
    int n; cin >> n;
    long a[n];
    vector<long> cum;
    cum.resize(n, 0L);
    long sum = 0L;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        sum %= 1000000007;
        if (i == 0) {
            cum[i] = a[0];
        } else {
            cum[i] += cum[i-1] + a[i];
            cum[i] %= 1000000007;
        }
    }

    long ans = 0L;
    for (int i = 0; i < n - 1; ++i) {
        ans += a[i] * (sum - cum[i] > 0 ? sum - cum[i] : 1000000007 + sum - cum[i]);
        ans %= 1000000007;
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
