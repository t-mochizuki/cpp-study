// g++ -std=c++11 main.cpp -I ..
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <nutshell/heap>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::set;
using nutshell::Heap;

const int INF = 1 << 30;

class Edge {
public:

    int _v = -1;
    int _w = -1;
    int _value = INF;

    Edge() {}
    Edge(int v, int w, int value): _v(v), _w(w), _value(value) {}
};

void solve() {
    int n; cin >> n;
    int a[n+1][n+1];
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            cin >> a[u][v];
        }
    }

    Edge b[10000];
    Heap<Edge> h(0, b);

    vector<int> C;
    C.resize(n+1, INF);

    int v = 1;

    set<int> F;
    F.insert(1);

    int k = 0;

    int ans = 0;
    while (k < n - 1) {
        for (int w = 1; w <= n; ++w) {
            auto it = F.find(w);
            if (it == F.end() && a[v][w] != -1) {
                h.insert(Edge(v, w, a[v][w]));
            }
        }

        int cost = INF;
        int vertex = -1;
        while (true) {
            if (h._heapSize == 0) {
                break;
            }

            Edge e = h.extract();

            auto it = F.find(e._w);
            if (it == F.end()) {
                cost = e._value;
                vertex = e._w;
                break;
            }
        }

        if (vertex == -1) {
            terminate();
        }

        F.insert(vertex);
        k++;
        ans += cost;
        v = vertex;
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
