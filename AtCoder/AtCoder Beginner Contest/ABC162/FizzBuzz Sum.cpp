#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

long series(long n, long a, long d) {
    return n * (2 * a + (n - 1) * d) / 2;
}

void solve() {
    long n; cin >> n;

    long n3 = n / 3;
    long n5 = n / 5;
    long n15 = n / 15;

    long y = series(n, 1, 1) - series(n3, 3, 3) - series(n5, 5, 5) + series(n15, 15, 15);

    cout << y << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("AtCoder/ABC162/FizzBuzz Sum.input");
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
