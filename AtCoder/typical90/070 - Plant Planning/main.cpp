// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::pair;
using std::abs;
using std::sort;

// キーワード: x, y 独立に考える

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

    int n;
    vector<long> x, y;

public:

    Program() {
        cin >> n;
        x.resize(n);
        y.resize(n);
        rep(i, 0, n) cin >> x[i] >> y[i];
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
    }

    void solve() {
        int m = x.size() / 2;
        long mx, my;
        if (x.size() % 2 == 0) {
            mx = (x[m-1] + x[m]) / 2;
            my = (y[m-1] + y[m]) / 2;
        } else {
            mx = x[m];
            my = y[m];
        }

        long ans = 0;
        rep(i, 0, n) {
            ans += abs(x[i]-mx);
            ans += abs(y[i]-my);
        }

        cout << ans << endl;
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Program p;
        p.solve();
    }
#else
    Program p;
    p.solve();
#endif

    return 0;
}
