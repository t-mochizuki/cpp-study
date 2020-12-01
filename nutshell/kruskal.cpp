#ifndef KRUSKAL
#define KRUSKAL 1

#include <vector>
#include <algorithm>
#include "edge"
#include "disjointset"

using std::vector;
using std::sort;
using nutshell::Edge;
using nutshell::DisjointSet;

namespace nutshell {

class Kruskal {
public:

    int _value = 0;

    Kruskal(int n, vector<Edge>& edges) {
        sort(edges.begin(), edges.end());

        DisjointSet F(n+1);

        for (auto e : edges) {
            if (F.find(e._u) != F.find(e._v)) {
                F.merge(e._u, e._v);
                _value += e._value;
            }
        }
    }
};

} // namespace nutshell

#endif // KRUSKAL
