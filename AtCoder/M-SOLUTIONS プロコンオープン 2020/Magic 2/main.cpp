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

bool f(int a, int b, int c, int k) {
    if (k == 0) {
        if (a < b && b < c) return true;
        else return false;
    } else {
        bool af = f(a*2,b,c,k-1);
        bool bf = f(a,b*2,c,k-1);
        bool cf = f(a,b,c*2,k-1);

        if (af || bf || cf) return true;
        else return false;
    }
}

void solve() {
    int a, b, c, k; cin >> a >> b >> c >> k;

    if(f(a,b,c,k)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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
