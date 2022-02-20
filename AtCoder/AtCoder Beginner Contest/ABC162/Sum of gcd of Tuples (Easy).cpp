#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

template<class T> inline T gcd(T a, T b) {
  while (b > 0) {
    T r = a % b;
    a = b;
    b = r;
  }

  return a;
}

void solve() {
    int k; cin >> k;

    int y = 0;
    for (int a = 1; a <= k; ++a) {
        for (int b = 1; b <= k; ++b) {
            for (int c = 1; c <= k; ++c) {
                y += gcd(gcd(a, b), c);
            }
        }
    }

    cout << y << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("AtCoder/ABC162/Sum of gcd of Tuples (Easy).input");
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
