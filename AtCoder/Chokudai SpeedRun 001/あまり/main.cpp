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

const long p = 1000000007;

template<class T> inline T pow(T base, T exponent) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return base * pow(base, exponent - 1);
    } else {
        T tmp = pow(base, exponent / 2);
        return tmp * tmp;
    }
}

void solve() {
    int n; cin >> n;
    long a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            ans = a[i];
        } else {
            long digits = to_string(a[i]).length();
            ans *= pow(10L, digits);
            ans += a[i];
            ans %= p;
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
