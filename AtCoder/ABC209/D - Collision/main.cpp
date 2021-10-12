// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::map;
using std::make_pair;
using std::priority_queue;
using std::greater;
using std::abs;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

using Weight = int;

class Edge {
public:

    int from;
    int to;
    Weight value;

    Edge(int from, int to, Weight value): from(from), to(to), value(value) {}

    friend bool operator<(const Edge& lhs, const Edge& rhs) {
        return lhs.value < rhs.value;
    }
    friend bool operator>(const Edge& lhs, const Edge& rhs) { return rhs < lhs; }
    friend bool operator<=(const Edge& lhs, const Edge& rhs) { return !(lhs > rhs); }
    friend bool operator>=(const Edge& lhs, const Edge& rhs) { return !(lhs < rhs); }
    friend bool operator==(const Edge& lhs, const Edge& rhs) {
        return lhs.value == rhs.value;
    }
    friend bool operator!=(const Edge& lhs, const Edge& rhs) { return !(lhs == rhs); }

    friend std::ostream& operator<<(std::ostream& os, const Edge& edge)
    {
        return os << edge.value;
    }
};

using Graph = map<int, vector<Edge>>;

class Dijkstra {
private:

    vector<int> prev;
    Graph& adjacency;
    priority_queue<Edge, vector<Edge>, greater<Edge>> que;

    const int INF = 1 << 30;

public:

    vector<int> d;

    Dijkstra(int N, int s, Graph& adjacency): adjacency(adjacency) {
        d.assign(N, INF);
        d[s] = 0;

        prev.assign(N, -1);

        que.push(Edge(INF, s, 0));
    }

    void debug() {
        rep(i, 0, d.size()) {
            if (i == 0) cout << d[i];
            else cout << "," << d[i];
        }
        cout << endl;
    }

    void solve() {
        while(!que.empty()) {
            int from = que.top().to; que.pop();

            for (auto edge : adjacency[from]) {
                if (d[edge.to] > d[from] + edge.value) {
                    d[edge.to] = d[from] + edge.value;
                    que.push(Edge(from, edge.to, d[edge.to]));
                    prev[edge.to] = from;
                }
            }
        }

        // debug();
    }
};

class Problem {
private:

    int N, Q;
    Graph adjacency;

    void make(int a, int b, Weight c, Graph& adjacency) {
        auto from = adjacency.find(a);
        if (from != adjacency.end()) {
            adjacency[a].push_back(Edge(a, b, c));
        } else {
            adjacency.insert(make_pair(a, vector<Edge>(1, Edge(a, b, c))));
        }
    }

public:

    Problem() {
        cin >> N >> Q;

        int a, b;
        rep(i, 0, N-1) {
            cin >> a >> b;
            a--; b--;

            make(a, b, 1, adjacency);
            make(b, a, 1, adjacency);
        }
    }

    void solve() {
        Dijkstra g(N, 0, adjacency);
        g.solve();

        int c, d;
        rep(i, 0, Q) {
            cin >> c >> d;
            c--; d--;
            int gdc = g.d[c];
            int gdd = g.d[d];
            if (abs(gdc - gdd) % 2 == 0) cout << "Town" << endl;
            else cout << "Road" << endl;
        }
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Problem p;
        p.solve();
    }
#else
    Problem p;
    p.solve();
#endif

    return 0;
}
