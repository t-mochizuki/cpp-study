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

// TODO: WA

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int ans = 0;
        for (int x = 1; x <= 100; ++x)
        for (int y = 1; y <= 100; ++y)
        for (int z = 1; z <= 100; ++z) {
            if (i == x * x + y * y + z * z + x * y + y * z + z * x) {
                ans++;
            }
        }
        cout << ans << endl;
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
