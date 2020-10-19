#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

void solve(int x) {
    int n; cin >> n;
    long c[n][n];
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            cin >> c[a][b];
        }
    }

    long y = 0;
    for (int b = 0; b < n; ++b) {
        long tmp = 0;
        for (int a = 0; a < n; ++a) {
            if (a+b < n) {
                tmp += c[a+b][a];
            }
        }
        y = max(y, tmp);
    }
    for (int b = 0; b < n; ++b) {
        long tmp = 0;
        for (int a = 0; a < n; ++a) {
            if (a+b < n) {
                tmp += c[a][a+b];
            }
        }
        y = max(y, tmp);
    }

    cout << "Case #" << x << ": " << y << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#else
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#endif

    return 0;
}
