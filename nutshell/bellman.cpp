#ifndef BELLMAN
#define BELLMAN 1

namespace nutshell {

#include <iostream>
#include <vector>
#include "graph"

using std::cout;
using std::endl;
using std::vector;

class BellmanFord {
public:

    bool _negativeCycle = false;
    vector<long> _dist;

    BellmanFord(Graph g, int source) {
        _dist.resize(g._n, INF);

        _dist[source] = 0;

        for (int t = 0; t < g._n; ++t) {
            relaxEdges(t, g);
        }

    }

    void relaxEdges(int t, Graph& g) {
        for (int u = 0; u < g._n; ++u) {
            if (_dist[u] == INF) {
                continue;
            }

            for (auto e : g._adjacencyList[u]) {
                if (_dist[e._v] > _dist[u] + e._value) {
                    _dist[e._v] = _dist[u] + e._value;
                    if (t == g._n - 1) {
                        _negativeCycle = true;
                    }
                }
            }
        }
    }

    void print() {
        if (_negativeCycle) {
            cout << "NEGATIVE CYCLE" << endl;
        } else {
            for (auto d : _dist) {
                if (d == INF) {
                    cout << "INF" << endl;
                } else {
                    cout << d << endl;
                }
            }
        }
    }

};

} // namespace nutshell

#endif // BELLMAN
