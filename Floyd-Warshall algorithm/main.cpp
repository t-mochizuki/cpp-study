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

const long INF = 1L << 60;

class Edge {
public:

    int _u = -1;
    int _v = -1;
    long _value = INF;

    Edge() {}
    Edge(int u, int v, long value): _u(u), _v(v), _value(value) {}

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
    std::vector<std::vector<Edge>> _adjacencyList;

    Graph(int n): _n(n) {
        _adjacencyList.resize(n);
    }

};

class BellmanFord {
public:

    bool _negativeCycle = false;

    BellmanFord(Graph& g, int source) {
        long dist[g._n];
        for (int i = 0; i < g._n; ++i) {
            dist[i] = INF;
        }

        dist[source] = 0;

        for (int t = 0; t < g._n; ++t) {
            relaxEdges(t, g, dist);
        }
    }

    void relaxEdges(int t, Graph& g, long* dist) {
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

};

class FloydWarshall {
public:

    FloydWarshall(Graph& g) {
        long dist[g._n][g._n];
        for (int u = 0; u < g._n; ++u) {
            for (int v = 0; v < g._n; ++v) {
                dist[u][v] = INF;
            }
        }

        for (int u = 0; u < g._n; ++u) {
            for (auto e : g._adjacencyList[u]) {
                dist[u][e._v] = e._value;
            }
        }

        for (int k = 0; k < g._n; ++k) {
            for (int i = 0; i < g._n; ++i) {
                for (int j = 0; j < g._n; ++j) {
                    if (dist[i][k] == INF) {
                        continue;
                    }
                    if (dist[k][j] == INF) {
                        continue;
                    }
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        for (int u = 0; u < g._n; ++u) {
            dist[u][u] = 0;
        }

        for (int u = 0; u < g._n; ++u) {
            for (int v = 0; v < g._n; ++v) {
                if (v == g._n - 1) {
                    if (dist[u][v] == INF) {
                        cout << "INF" << endl;
                    } else {
                        cout << dist[u][v] << endl;
                    }
                } else {
                    if (dist[u][v] == INF) {
                        cout << "INF" << " ";
                    } else {
                        cout << dist[u][v] << " ";
                    }
                }
            }
        }
    }

};

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
