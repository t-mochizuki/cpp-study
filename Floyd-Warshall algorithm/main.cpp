#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "nutshell/edge"
#include "nutshell/graph"
#include "nutshell/bellman"
#include "nutshell/floyd"

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using nutshell::Edge;
using nutshell::Graph;
using nutshell::BellmanFord;
using nutshell::FloydWarshall;

void solve() {
    int n, m; cin >> n >> m;

    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        long w; cin >> w;
        g._adjacencyList[u].push_back(Edge(u, v, w));
    }

    BellmanFord b(g, 0);

    if (b._negativeCycle) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        FloydWarshall f(g);
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
