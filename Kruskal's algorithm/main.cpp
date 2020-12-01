#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <nutshell/edge>
#include <nutshell/kruskal>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using nutshell::Edge;
using nutshell::Kruskal;

void solve() {
    int n; cin >> n;
    vector<Edge> edges;
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            long value = 0; cin >> value;
            if (value != -1) {
                edges.push_back(Edge(u, v, value));
            }
        }
    }

    Kruskal kruskal(n, edges);

    cout << kruskal._value << endl;
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
