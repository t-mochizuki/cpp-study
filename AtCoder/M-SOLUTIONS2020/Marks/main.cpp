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

void solve() {
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - k; ++i) {
        if (a[i+k] > a[i]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
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
