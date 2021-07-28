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
using std::sort;
using std::to_string;
using std::lower_bound;
using std::distance;
using std::deque;
using std::set;

const long MOD = 1e9 + 7;

struct Edge {
    int to;
    long w;
    Edge(int to, long w): to(to), w(w) {}
};

class Problem {
private:

    int N;
    vector<vector<Edge> > g;

public:
    Problem() {
        cin >> N;
        g.resize(N);
        for (int j = 0; j < N-1; ++j) {
            int u, v;
            long w;
            cin >> u >> v >> w;
            u--; v--;
            g[u].push_back(Edge(v, w));
            g[v].push_back(Edge(u, w));
        }
    }

    // 木にある1の数を求める。
    int dfs(int from, int x, int parent) {
        int res = x;
        for (auto e : g[from]) {
            // 無向グラフなので戻らないようにする。
            if (e.to == parent) continue;
            res += dfs(e.to, x^(e.w&1), from);
        }
        return res;
    }

    long summation() {
        long x = dfs(0, 0, -1);
        return ((N - x) * x) % MOD;
    }

    void solve() {
        long ans = 0;
        long factor = 1;
        for (int j = 0; j < 60; ++j) {
            ans += summation() * factor;
            ans %= MOD;
            for (int u = 0; u < N; ++u) for (int v = 0; v < g[u].size(); ++v) {
                g[u][v].w >>= 1;
            }
            factor *= 2;
            factor %= MOD;
        }
        cout << ans << endl;
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
