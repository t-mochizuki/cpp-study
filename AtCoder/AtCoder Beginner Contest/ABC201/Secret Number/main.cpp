// g++ -std=c++14 -DDEV=1 -Wall main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

void solve() {
    char s[11]; cin >> s;
    int ans = 0;
    for (int i = 0; i < 10000; ++i) {
        int a = i / 1000;
        int b = i % 1000 / 100;
        int c = i % 100 / 10;
        int d = i % 10;

        char t[11] = "xxxxxxxxxx";
        t[a] = 'o';
        t[b] = 'o';
        t[c] = 'o';
        t[d] = 'o';

        bool ng = false;
        for (int j = 0; j < 10; ++j) {
            if (s[j] == 'o' && t[j] != 'o') {
                ng = true;
            }
            if (s[j] == 'x' && t[j] != 'x') {
                ng = true;
            }
        }

        if (!ng) {
            ans++;
        }
    }

    cout << ans << endl;
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
