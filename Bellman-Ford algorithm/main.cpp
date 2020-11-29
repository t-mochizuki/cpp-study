#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <nutshell/edge>
#include <nutshell/graph>
#include <nutshell/bellman>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using nutshell::Edge;
using nutshell::Graph;
using nutshell::BellmanFord;

const int INF = 1 << 30;



void solve() {
    int n, m, r; cin >> n >> m >> r;

    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        g._adjacencyList[u].push_back(Edge(u, v, w));
    }

    BellmanFord b(g, r);
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
