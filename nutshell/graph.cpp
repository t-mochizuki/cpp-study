#ifndef GRAPH
#define GRAPH 1

#include <vector>
#include "edge"

using std::vector;

namespace nutshell {

class Graph {
public:

    int _n;
    vector<vector<Edge>> _adjacencyList;

    Graph(int n): _n(n) {
        _adjacencyList.resize(n);
    }

};

} // namespace nutshell

#endif // GRAPH
