#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <nutshell/edge>
#include <nutshell/graph>
#include <nutshell/dijkstra>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using nutshell::Edge;
using nutshell::Graph;
using nutshell::Dijkstra;

const long INF = 1L << 60;

void solve() {
    int n; cin >> n;

    Graph g(n);
    for (int i = 0; i < n; ++i) {
        int u; cin >> u;
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            int v; cin >> v;
            long c; cin >> c;
            g._adjacencyList[u].push_back(Edge(u, v, c));
        }
    }

    Dijkstra<long> d(g, 0);

    for (int v = 0; v < n; ++v) {
        cout << v << " " << d._dist[v] << endl;
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
