#ifndef DISJOINT_SET
#define DISJOINT_SET 1

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

namespace nutshell {

class DisjointSet {
public:

    template<class T> void swap(T &A, T &B) {
        T tmp = A;
        A = B;
        B = tmp;
    }

    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        rank.resize(n, 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
            return parent[x];
        } else {
            return x;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    // union by rank
    void link(int x, int y) {
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);

        if (rx == ry) {
            return ;
        }

        link(rx, ry);
    }
};

}
#endif // DISJOINT_SET
