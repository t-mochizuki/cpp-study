#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

const int INF = 1 << 30;


class Edge {
public:

    int _u = -1;
    int _v = -1;
    int _value = INF;

    Edge() {}
    Edge(int u, int v, int value): _u(u), _v(v), _value(value) {}

    friend bool operator<(const Edge& lhs, const Edge& rhs) {
        return lhs._value < rhs._value;
    }
    friend bool operator>(const Edge& lhs, const Edge& rhs) { return rhs < lhs; }
    friend bool operator<=(const Edge& lhs, const Edge& rhs) { return !(lhs > rhs); }
    friend bool operator>=(const Edge& lhs, const Edge& rhs) { return !(lhs < rhs); }
    friend bool operator==(const Edge& lhs, const Edge& rhs) {
        return lhs._value == rhs._value;
    }
    friend bool operator!=(const Edge& lhs, const Edge& rhs) { return !(lhs == rhs); }

    friend std::ostream& operator<<(std::ostream& os, const Edge& e)
    {
        return os << e._v;
    }
};

class Graph {
public:

    int _n;
    vector<vector<Edge>> _adjacencyList;

    Graph(int n): _n(n) {
        _adjacencyList.resize(n);
    }

};

class BellmanFord {
public:

    bool _negativeCycle = false;

    BellmanFord(Graph g, int source) {
        int dist[g._n];
        for (int i = 0; i < g._n; ++i) {
            dist[i] = INF;
        }

        dist[source] = 0;

        for (int t = 0; t < g._n; ++t) {
            bool updated = false;
            for (int u = 0; u < g._n; ++u) {
                if (dist[u] == INF) {
                    continue;
                }

                for (auto e : g._adjacencyList[u]) {
                    if (dist[e._v] > dist[u] + e._value) {
                        dist[e._v] = dist[u] + e._value;
                        if (t == g._n - 1) {
                            _negativeCycle = true;
                        }
                    }
                }
            }
        }

        if (_negativeCycle) {
            cout << "NEGATIVE CYCLE" << endl;
        } else {
            for (auto d : dist) {
                if (d == INF) {
                    cout << "INF" << endl;
                } else {
                    cout << d << endl;
                }
            }
        }
    }

};

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
