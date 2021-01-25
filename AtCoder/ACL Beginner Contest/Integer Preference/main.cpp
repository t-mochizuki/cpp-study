#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;

template<class T> inline void swap(T &A, T &B) {
    T tmp = A;
    A = B;
    B = tmp;
}

void solve() {
    long a, b, c, d; cin >> a >> b >> c >> d;

    if (a > c) {
        swap(a, c);
        swap(b, d);
    }

    if (c > b) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
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
