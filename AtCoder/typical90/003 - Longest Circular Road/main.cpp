// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::map;
using std::make_pair;

// キーワード: 木の直径は最短距離計算を2回やる

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int N;
    map<int, vector<int>> edge;
    vector<int> dist/*ance*/;
    vector<bool> visited;

public:
    Problem() {
        cin >> N;

        int a, b;
        rep(i, 0, N-1) {
            cin >> a >> b;
            a--; b--;

            auto it = edge.find(a);
            if (it == edge.end()) {
                edge.insert(make_pair(a, vector<int>(1, b)));
            } else {
                edge[a].push_back(b);
            }

            it = edge.find(b);
            if (it == edge.end()) {
                edge.insert(make_pair(b, vector<int>(1, a)));
            } else {
                edge[b].push_back(a);
            }
        }

        dist.assign(N, 0);

        visited.assign(N, false);
    }

    void traverse(int from, int distance) {
        if (visited[from]) return ;

        dist[from] = distance;
        visited[from] = true;

        for (auto to : edge[from]) {
            traverse(to, distance+1);
        }
    }

    void debug() {
        bool first = true;
        for (auto d : dist) {
            if (first) {
                first = false;
                cout << d;
            } else cout << "," << d;
        }
        cout << endl;
    }

    void solve() {

        traverse(0, 0);

        int from = 0, distance = 0;
        rep(i, 0, N) {
            if (dist[i] > distance) {
                from = i;
                distance = dist[i];
            }
        }

        dist.clear();
        dist.assign(N, 0);
        visited.clear();
        visited.assign(N, false);

        distance = 0;
        traverse(from, distance);

        rep(i, 0, N) {
            if (dist[i] > distance) {
                from = i;
                distance = dist[i];
            }
        }

        cout << distance+1 << endl;
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
