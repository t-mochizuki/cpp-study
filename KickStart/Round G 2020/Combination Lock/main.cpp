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

template<class T> inline T abs(T X) {
    return X > 0 ? X : -X;
}

template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

void solve(int x) {
    long w, n; cin >> w >> n;
    long c[w];
    for (int j = 0; j < w; ++j) {
        cin >> c[j];
    }
    long y = 1000000000000000000;
    for (int a = 1; a <= n; ++a) {
        long tmp = 0;
        for (int j = 0; j < w; ++j) {
            if (abs(c[j] - a) > abs((n + a) - c[j])) {
                tmp += abs((n + a) - c[j]);
            } else if (abs(c[j] - a) > abs(c[j] - (a - n))) {
                tmp += abs(c[j] - (a - n));
            } else {
                tmp += abs(c[j] - a);
            }
        }
        y = min(y, tmp);
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
