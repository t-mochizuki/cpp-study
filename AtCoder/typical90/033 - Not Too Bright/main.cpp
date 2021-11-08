// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

// キーワード: コーナーケースに気を付けよう

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

//#.#
//...
//#.#

class Problem {
private:

    int H, W;

public:

    Problem() {
        cin >> H >> W;
        assert(H >= 1);
        assert(W >= 1);
        assert(H <= 100);
        assert(W <= 100);
    }

    void solve() {
        if (H == 1 || W == 1) {
            cout << H * W << endl;
            return ;
        }

        int ans = 0;
        rep(i, 0, H) rep(j, 0, W) {
            if (i % 2 == 0 && j % 2 == 0) ans++;
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
        Problem p;
        p.solve();
    }
#else
    Problem p;
    p.solve();
#endif

    return 0;
}
