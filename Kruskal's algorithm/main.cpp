#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <nutshell/disjointset>
#include <nutshell/edge>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using nutshell::DisjointSet;
using nutshell::Edge;

void solve() {
    int n; cin >> n;
    vector<Edge> E;
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            int value = 0; cin >> value;
            if (value != -1) {
                E.push_back(Edge(u, v, value));
            }
        }
    }

    sort(E.begin(), E.end());

    // for (int i = 0; i < E.size(); ++i) {
    //     if (i == E.size() - 1) {
    //         cout << E[i]._value << endl;
    //     } else {
    //         cout << E[i]._value << " ";
    //     }
    // }

    DisjointSet F(n+1);

    int ans = 0;
    for (auto e : E) {
        if (F.find(e._u) != F.find(e._v)) {
            F.merge(e._u, e._v);
            ans += e._value;
        }
    }

    cout << ans << endl;
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
