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

// キーワード: 各頂点への最短経路はダイクストラ

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

class Dijkstra {
private:

    vector<int> prev;
    map<int, map<int, Weight>>& adjacency;
    priority_queue<Edge, vector<Edge>, greater<Edge>> que;

    const int INF = 1 << 30;

public:

    vector<int> d;

    Dijkstra(int N, int s, map<int, map<int, Weight>>& adjacency): adjacency(adjacency) {
        d.resize(N);
        prev.resize(N);
        rep(i, 0, N) {
            if (i == s) d[i] = 0;
            else d[i] = INF;

            prev[i] = -1;
        }

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
            Edge edge = que.top(); que.pop();

            int from = edge.to;
            for (auto m : adjacency[from]) {
                if (d[m.first] > d[from] + m.second) {
                    d[m.first] = d[from] + m.second;
                    que.push(Edge(from, m.first, d[m.first]));
                    prev[m.first] = from;
                }
            }
        }

        // debug();
    }
};

class Problem {
private:

    int N, M;
    map<int, map<int, Weight>> adjacency;

    void make(int a, int b, Weight c, map<int, map<int, Weight>>& adjacency) {
        auto from = adjacency.find(a);
        if (from != adjacency.end()) {
            auto to = adjacency[a].find(b);
            if (to != adjacency[a].end()) {
                adjacency[a][b] = c;
            } else {
                adjacency[a].insert(make_pair(b, c));
            }
        } else {
            map<int, Weight> tmp;
            tmp.insert(make_pair(b, c));
            adjacency.insert(make_pair(a, tmp));
        }
    }

public:
    Problem() {
        cin >> N >> M;

        int a, b, c;
        rep(i, 0, M) {
            cin >> a >> b >> c;
            a--; b--;

            make(a, b, c, adjacency);
            make(b, a, c, adjacency);
        }
    }

    void solve() {
        Dijkstra d1(N, 0, adjacency);
        d1.solve();

        Dijkstra dN(N, N-1, adjacency);
        dN.solve();

        rep(i, 0, N) {
            cout << d1.d[i] + dN.d[i] << endl;
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
