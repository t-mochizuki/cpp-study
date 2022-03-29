// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <tuple>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::string;
using std::map;
using std::pair;
using std::deque;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::abs;
using std::sort;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

// (A mod P)(A mod P)...(A mod P) = AA...A mod P
class Program {
private:

    long n, p, q;
    vector<long> a;

public:

    Program() {
        cin >> n >> p >> q;
        a.resize(n);
        rep(i, 0, n) {
            cin >> a[i];
            a[i] %= p;
        }
        sort(a.begin(), a.end());
    }

    void solve() {
        long ans = 0;
        rep(i1, 0, n) rep(i2, i1+1, n) rep(i3, i2+1, n) rep(i4, i3+1, n) rep(i5, i4+1, n) {
            long x = 1;
            x *= a[i1];
            x %= p;

            x *= a[i2];
            x %= p;

            x *= a[i3];
            x %= p;

            x *= a[i4];
            x %= p;

            x *= a[i5];
            x %= p;

            if (x == q) {
                // printf("%ld, %ld, %ld, %ld, %ld\n", a[i1], a[i2], a[i3], a[i4], a[i5]);
                ans++;
            }
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
