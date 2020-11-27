#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <nutshell/disjointset>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using nutshell::DisjointSet;

void solve() {
    int n, q; cin >> n >> q;

    DisjointSet st = DisjointSet(n);

    for (int i = 0; i < q; ++i) {
        int command; cin >> command;
        int x, y; cin >> x >> y;
        if (command == 0) {
            st.merge(x, y);
        } else {
            cout << st.same(x, y) << endl;
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
