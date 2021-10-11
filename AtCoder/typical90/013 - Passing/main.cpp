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
using std::pair;
using std::make_pair;
using std::priority_queue;
using std::greater;

// キーワード: 各頂点への最短経路はダイクストラ

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

using Weight = int;

class Dijkstra {
private:

    vector<pair<int, Weight>>* adjacency;
    priority_queue<pair<Weight, int>, vector<pair<Weight, int>>, greater<pair<Weight, int>>> que;

    const int INF = 1 << 30;

public:

    vector<int> d;

    Dijkstra(int N, int s, vector<pair<int, Weight>>* adjacency): adjacency(adjacency) {
        d.assign(N, INF);
        d[s] = 0;

        que.push(make_pair(0, s));
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
            int from = que.top().second; que.pop();

            rep(i, 0, adjacency[from].size()) {
                int to = adjacency[from][i].first;
                Weight value = adjacency[from][i].second;
                if (d[to] > d[from] + value) {
                    d[to] = d[from] + value;
                    que.push(make_pair(d[to], to));
                }
            }
        }

        // debug();
    }
};

class Problem {
private:

    int N, M;
    vector<pair<int, Weight>> adjacency[100000];

public:

    Problem() {
        cin >> N >> M;

        int a, b, c;
        rep(i, 0, M) {
            cin >> a >> b >> c;
            a--; b--;

            adjacency[a].push_back(make_pair(b, c));
            adjacency[b].push_back(make_pair(a, c));
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
