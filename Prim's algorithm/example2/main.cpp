// g++ -std=c++11 main.cpp -I ../..
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <nutshell/minheap>
#include <nutshell/edge>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::set;
using nutshell::MinHeap;
using nutshell::Edge;

const long INF = 1L << 60;

void solve() {
    int n; cin >> n;
    long a[n+1][n+1];
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            cin >> a[u][v];
        }
    }

    Edge b[10000];
    MinHeap<Edge> h(0, b);

    vector<long> C;
    C.resize(n+1, INF);

    auto u = 1;

    set<int> F;
    F.insert(1);

    auto k = 0;

    auto ans = 0;
    while (k < n - 1) {
        for (int v = 1; v <= n; ++v) {
            if (F.find(v) == F.end() && a[u][v] != -1) {
                h.insert(Edge(u, v, a[u][v]));
            }
        }

        auto value = INF;
        auto v = -1;
        while (true) {
            if (h._heapSize == 0) {
                break;
            }

            Edge e = h.extract();

            if (F.find(e._v) == F.end()) {
                value = e._value;
                v = e._v;
                break;
            }
        }

        if (v == -1) {
            terminate();
        }

        F.insert(v);
        k++;
        ans += value;
        u = v;
    }

    cout << ans << endl;
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
