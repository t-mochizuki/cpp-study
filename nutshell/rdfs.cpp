/*
g++ -std=c++14 -c rdfs.cpp
 */
#ifndef RDFS
#define RDFS 1

#include <vector>
#include <stack>

using std::vector;
using std::stack;

using Graph = vector<vector<int>>;

namespace nutshell {

class RecursiveDepthFirstSearch {
public:

    vector<bool> seen;

    RecursiveDepthFirstSearch(int N) {
        seen.assign(N, false);
    }

    void search(Graph &g, int u) {
        seen[u] = true;

        for (auto v : g[u]) {
            if (seen[v]) continue;

            // 行き掛け
            // ...

            search(g, v);
        }

        // 帰り掛け
        // ...
    }

};

} // namespace nutshell

#endif // RDFS
