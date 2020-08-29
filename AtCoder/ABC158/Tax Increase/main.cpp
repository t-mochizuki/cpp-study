#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve() {
    int A, B; cin >> A >> B;

    for (int i = 1; i <= 1250; ++i) {
        if (i * 8 / 100 == A && i * 10 / 100 == B) {
            cout << i << endl;
            return ;
        }
    }

    cout << -1 << endl;
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
