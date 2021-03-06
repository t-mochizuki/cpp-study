#include <stdio.h>
#include <iostream>
#include <fstream>
#include <nutshell/graph>
#include <nutshell/queue>
#include <nutshell/edge>
#include <nutshell/bfs>
#include <vector>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using nutshell::Graph;
using nutshell::Queue;
using nutshell::Edge;
using nutshell::BreadthFirstSearch;
using std::vector;

const int INF = 1 << 30;

void solve() {
    int n; cin >> n;
    Graph g(n+1);
    for (int i = 1; i <= n; ++i) {
        int u; cin >> u;
        int k; cin >> k;
        for (int j = 1; j <= k; ++j) {
            int v; cin >> v;
            g._adjacencyList[u].push_back(Edge(u, v, 0));
        }
    }

    BreadthFirstSearch<int> bfs(g, 1);

    for (int i = 1; i <= n; ++i) {
        if (bfs._dist[i] == INF) {
            cout << i << " " << -1 << endl;
        } else {
            cout << i << " " << bfs._dist[i] << endl;
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
