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

string toString(long n) {
    if (n > 26) {
        char c[2];
        c[0] = (char)(96 + (n % 26));
        c[1] = '\0';
        return toString(n / 26) + c;
    } else {
        char c[2];
        c[0] = (char)(96 + n);
        c[1] = '\0';
        return c;
    }
}

void solve() {
    long n; cin >> n;

    cout << toString(n) << endl;
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
