#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::map;
using std::make_pair;
using std::sqrt;

void solve() {
    long n; cin >> n;

    long ans = 0;
    for (int i = 1; i <= n; ++i) {
        // 整数n以下にiの倍数はy個ある
        long y = n / i;
        // 等差はi
        ans += i * y * (y + 1) / 2;
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
