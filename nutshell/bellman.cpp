#ifndef BELLMAN
#define BELLMAN 1

namespace nutshell {

#include <iostream>
#include "graph"

using std::cout;
using std::endl;

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

} // namespace nutshell

#endif // BELLMAN
