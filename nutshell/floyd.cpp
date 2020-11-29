#ifndef FLOYD
#define FLOYD 1

namespace nutshell {

#include <iostream>
#include "graph"

using std::cout;
using std::endl;

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

} // namespace nutshell

#endif // FLOYD
