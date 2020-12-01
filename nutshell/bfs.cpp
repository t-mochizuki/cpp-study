#ifndef BFS
#define BFS 1

#include <vector>
#include "graph"
#include "edge"
#include "queue"

using std::vector;
using nutshell::Graph;
using nutshell::Edge;
using nutshell::Queue;

namespace nutshell {

template<class T>
class BreadthFirstSearch {
public:

    vector<T> _dist;

    BreadthFirstSearch(Graph g, int s) {
        int a[105];
        Queue<int> que(a);

        _dist.resize(g._n, INF);

        que.enqueue(s);
        _dist[s] = 0;

        while (!que.empty()) {
            int u = que.dequeue();
            for (auto e : g._adjacencyList[u]) {
                if (_dist[e._v] == INF) {
                    _dist[e._v] = _dist[e._u] + 1;
                    que.enqueue(e._v);
                }
            }
        }
    }

};

} // namespace nutshell

#endif // BFS
