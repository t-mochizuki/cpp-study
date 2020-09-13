#include <stdio.h>
#include <iostream>
#include <fstream>
#include <atcoder/fenwicktree>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using atcoder::fenwick_tree;

void solve() {
    int N, Q; cin >> N >> Q;
    fenwick_tree<long> fe(N);

    for (int i = 0; i < N; ++i) {
        long a; cin >> a;
        fe.add(i, a);
    }

    for (int i = 0; i < Q; ++i) {
        long t; cin >> t;
        if (t == 0) {
            long p, x; cin >> p >> x;
            fe.add(p, x);
        } else if (t == 1) {
            int l, r; cin >> l >> r;
            cout << fe.sum(l, r) << endl;
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
