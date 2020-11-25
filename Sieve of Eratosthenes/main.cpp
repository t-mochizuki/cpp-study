#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i < n; ++i) {
        a[i] = 1;
    }

    for (int i = 4; i < n; i += 2) {
        a[i] = 0;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (a[i] == 0) {
            continue;
        }
        for (int j = i * 2; j < n; j += i) {
            a[j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
            if (a[i] == 1) {
                cout << a[i] << endl;
            } else {
                cout << endl;
            }
        } else {
            if (a[i] == 1) {
                cout << i << " ";
            }
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
