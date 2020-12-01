#ifndef DIJKSTRA
#define DIJKSTRA 1

#include <vector>
#include <set>
#include "graph"
#include "edge"
#include "heap"

using std::vector;
using std::set;
using nutshell::Graph;
using nutshell::Edge;
using nutshell::MinHeap;

namespace nutshell {

template<class T>
class Dijkstra {
public:

    vector<T> _dist;
    vector<int> _parent;

    Dijkstra(Graph g, int s) {
        _dist[g._n];
        _dist.resize(g._n, INF);
        _dist[s] = 0L;

        Edge a[500005];
        MinHeap<Edge> h(0, a);
        h.insert(Edge(-1, s, 0));

        _parent.resize(g._n, -1);

        set<int> F;

        while (h._heapSize != 0) {
            Edge edge = h.extract();
            int u = edge._v;
            int value = edge._value;

            if (_dist[u] < value) {
                continue;
            }

            F.insert(u);

            for (auto e : g._adjacencyList[u]) {
                if (F.find(e._v) != F.end()) {
                    continue;
                }
                if (_dist[e._v] > _dist[u] + e._value) {
                    _dist[e._v] = _dist[u] + e._value;
                    h.insert(Edge(u, e._v, _dist[e._v]));
                    _parent[e._v] = u;
                }
            }
        }
    }
};

} // namespace nutshell

#endif // DIJKSTRA
