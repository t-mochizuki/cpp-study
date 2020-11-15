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
using std::to_string;

void solve(int x) {
    long l, r; cin >> l >> r;
    if (l>1000||r>1000) terminate();

    long y = 0;
    for (long a = l; a <= r; ++a) {
        string s = to_string(a);
        bool flag = true;
        for (long b = 0; b < s.length(); ++b) {
            if (b%2==0) {
                if ((s[b]-'0')%2==0) {
                    flag = false;
                    break;;
                }
            } else {
                if ((s[b]-'0')%2==1) {
                    flag = false;
                    break;;
                }
            }
        }
        if (flag) y++;
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
