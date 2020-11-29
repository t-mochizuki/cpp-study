#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <nutshell/edge>
#include <nutshell/heap>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::set;
using nutshell::Edge;
using nutshell::MinHeap;

const long INF = 1L << 60;

void solve() {
    int n; cin >> n;

    vector<vector<Edge>> E;
    E.resize(n);
    for (int i = 0; i < n; ++i) {
        int u; cin >> u;
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            int v; cin >> v;
            long c; cin >> c;
            E[u].push_back(Edge(u, v, c));
        }
    }

    long dist[n];
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (i == s) {
            dist[i] = 0L;
        } else {
            dist[i] = INF;
        }
    }

    Edge a[500005];
    MinHeap<Edge> h(0, a);
    h.insert(Edge(s, s, 0));

    int parent[n];
    for (int i = 0; i < n; ++i) {
        parent[i] = -1;
    }

    set<int> T;

    while (h._heapSize != 0) {
        Edge tmp = h.extract();
        int u = tmp._v;
        int cost = tmp._value;

        if (dist[u] < cost) {
            continue;
        }

        T.insert(u);

        for (auto e : E[u]) {
            if (T.find(e._v) != T.end()) {
                continue;
            }
            if (dist[e._v] > dist[u] + e._value) {
                dist[e._v] = dist[u] + e._value;
                h.insert(Edge(u, e._v, dist[e._v]));
                parent[e._v] = u;
            }
        }
    }

    for (int v = 0; v < n; ++v) {
        cout << v << " " << dist[v] << endl;
    }

    // for (int v = 0; v < n; ++v) {
    //     if (v == n - 1) {
    //         cout << dist[v] << endl;
    //     } else {
    //         cout << dist[v] << " ";
    //     }
    // }

    // for (int v = 0; v < n; ++v) {
    //     if (v == n - 1) {
    //         cout << parent[v] << endl;
    //     } else {
    //         cout << parent[v] << " ";
    //     }
    // }
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
