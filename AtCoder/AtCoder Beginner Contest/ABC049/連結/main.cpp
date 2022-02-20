// g++ -std=c++14 -DDEV=1 -Wall main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::map;
using std::make_pair;
using std::pair;
using std::sort;
using std::to_string;
using std::lower_bound;
using std::distance;
using std::deque;
using std::set;

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

void solve() {
    int n, k, l; cin >> n >> k >> l;

    DisjointSet road = DisjointSet(n);
    for (int i = 0; i < k; ++i) {
        int x, y; cin >> x >> y;
        x--; y--; // zero origin
        road.merge(x, y);
    }

    DisjointSet railroad = DisjointSet(n);
    for (int i = 0; i < l; ++i) {
        int x, y; cin >> x >> y;
        x--; y--; // zero origin
        railroad.merge(x, y);
    }

    map<pair<int, int>, int> m;
    for (int i = 0; i < n; ++i) {
        pair<int, int> p = make_pair(road.find(i), railroad.find(i));

        map<pair<int, int>, int>::iterator it = m.find(p);
        if (it != m.end()) {
            m[p]++;
        } else {
            m.insert(make_pair(p, 1));
        }
    }

    for (int i = 0; i < n; ++i) {
        pair<int, int> p = make_pair(road.find(i), railroad.find(i));

        map<pair<int, int>, int>::iterator it = m.find(p);
        if (it != m.end()) {
            if (i == 0) {
                cout << it->second;
            } else {
                cout << " " << it->second;
            }
        }
    }
    cout << endl;
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
