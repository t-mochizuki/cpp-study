#include <stdio.h>
#include <iostream>
#include <fstream>
#include <atcoder/dsu>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using atcoder::dsu;

void solve() {
    int N, Q; cin >> N >> Q;
    dsu d(N);
    for (int i = 0; i < Q; ++i) {
        int t, u, v; cin >> t >> u >> v;

        if (t == 0) {
            d.merge(u, v);
        } else if (t == 1) {
            cout << (d.same(u, v) ? 1 : 0) << endl;
        } else {
            //
        }
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
