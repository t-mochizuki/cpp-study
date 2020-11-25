#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

template<class T> inline void swap(T &A, T &B) {
    T tmp = A;
    A = B;
    B = tmp;
}

class DisjointSet {
public:

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

void solve() {
    int n, q; cin >> n >> q;

    DisjointSet st = DisjointSet(n);

    for (int i = 0; i < q; ++i) {
        int command; cin >> command;
        int x, y; cin >> x >> y;
        if (command == 0) {
            st.merge(x, y);
        } else {
            cout << st.same(x, y) << endl;
        }
    }
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
