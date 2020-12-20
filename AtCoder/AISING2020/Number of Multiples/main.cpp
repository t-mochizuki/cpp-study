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
    int L, R, d; cin >> L >> R >> d;
    cout << R / d - (L - 1) / d << endl;
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
