// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::min;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

struct Graph {
    struct Edge {
        int rev, from, to, cap;
        Edge(int rev, int from, int to, int cap): rev(rev), from(from), to(to), cap(cap) {}
    };

    vector<vector<Edge>> list;

    Graph(int N): list(N) {}

    size_t size() {
        return list.size();
    }

    vector<Edge> &operator [] (int i) {
        return list[i];
    }

    Edge& redge(const Edge &e) {
        return list[e.to][e.rev];
    }

    void run(Edge &e, int cap) {
        e.cap -= cap;
        redge(e).cap += cap;
    }

    void addEdge(int from, int to, int cap) {
        int fromRev = list[from].size();
        int toRev = list[to].size();

        list[from].push_back(Edge(toRev, from, to, cap));
        list[to].push_back(Edge(fromRev, to, from, 0));
    }

};

struct FordFulkerson {
    static const int INF = 1 << 30;

    vector<bool> seen;

    FordFulkerson() {}

    int stConnectivity(Graph &g, int s, int t, int f) {
        if (s == t) return f;

        seen[s] = true;

        for (auto &e : g[s]) {
            if (seen[e.to]) continue;

            if (e.cap == 0) continue;

            int flow = stConnectivity(g, e.to, t, min(f, e.cap));

            if (flow == 0) continue;

            g.run(e, flow);

            return flow;
        }

        // not found
        return 0;
    }

    int solve(Graph &g, int s, int t) {
        int ret = 0;

        while (true) {
            seen.assign(g.size(), false);

            int flow = stConnectivity(g, s, t, INF);

            if (flow == 0) return ret;
            else ret += flow;
        }

        terminate();
    }
};


class Program {
private:

public:

    Program() {
    }

    void solve() {
        int X, Y, M;
        cin >> X >> Y >> M;
        int N = X+Y+2;
        int s = N-2;
        int t = N-1;
        Graph g(N);
        rep(u, 0, X) {
            g.addEdge(s, u, 1);
        }
        rep(v, 0, Y) {
            g.addEdge(v+X, t, 1);
        }
        rep(i, 0, M) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v+X, 1);
        }

        FordFulkerson ff;
        cout << ff.solve(g, s, t) << endl;
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Program p;
        p.solve();
    }
#else
    Program p;
    p.solve();
#endif

    return 0;
}
