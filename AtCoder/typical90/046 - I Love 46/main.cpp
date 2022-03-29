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

// 46で割れることに関心がある
// nが大きい: 同じ整数が重複する
class Program {
private:

    int n;
    vector<long> a, b, c;

public:

    Program() {
        cin >> n;
        long A, B, C;
        a.assign(46, 0);
        rep(i, 0, n) {
            cin >> A;
            A %= 46;
            a[A]++;
        }
        b.assign(46, 0);
        rep(i, 0, n) {
            cin >> B;
            B %= 46;
            b[B]++;
        }
        c.assign(46, 0);
        rep(i, 0, n) {
            cin >> C;
            C %= 46;
            c[C]++;
        }
    }

    void solve() {
        long ans = 0;
        rep(ia, 0, a.size()) rep(ib, 0, b.size()) rep(ic, 0, c.size()) {
            if ((ia + ib + ic) % 46 == 0) {
                ans += a[ia] * b[ib] * c[ic];
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
