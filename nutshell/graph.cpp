#ifndef GRAPH
#define GRAPH 1

namespace nutshell {

#include <vector>
#include "edge"

class Graph {
public:

    int _n;
    std::vector<std::vector<Edge>> _adjacencyList;

    Graph(int n): _n(n) {
        _adjacencyList.resize(n);
    }

};

} // namespace nutshell

#endif // GRAPH
