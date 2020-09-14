#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::sort;
using std::vector;
using std::map;
using std::make_pair;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    // for (auto a : v) {
    //     cout << a << endl;
    // }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bool notDivisible = true;

        if (i < n - 1) {
            // cout << v[i] << "==" << v[i+1] << endl;
            if (v[i] == v[i + 1]) {
                continue;
            }
        }

        for (int j = i - 1; j >= 0; --j) {
            if (v[i] % v[j] == 0) {
                notDivisible = false;
                break;
            }
        }

        if (notDivisible) {
            ans++;
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
