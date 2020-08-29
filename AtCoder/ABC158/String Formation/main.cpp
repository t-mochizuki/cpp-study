#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::reverse;

void solve() {
    string s; cin >> s;
    int q; cin >> q;

    int direction = 0;
    for (int a = 1; a <= q; ++a) {
        int t; cin >> t;
        if (t == 1) {
            direction++;
            direction %= 2;
        } else {
            int f; cin >> f;
            char c; cin >> c;
            if (direction == 0 && f == 1 || direction == 1 && f == 2) {
                // 先頭に文字を追加
                s.insert(s.begin(), c);
            } else {
                // 末尾に文字を追加
                s.append(1, c);
            }
        }
    }

    if (direction == 1) {
        reverse(s.begin(), s.end());
    }

    cout << s << endl;
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
