#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::set;

const int INF = 1 << 30;

void solve() {
    int n; cin >> n;
    int a[n+1][n+1];
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            cin >> a[u][v];
        }
    }

    vector<int> C;
    C.resize(n+1, INF);

    set<int> F, Q;
    for (int i = 2; i <= n; ++i) {
        Q.insert(i);
    }

    int v = 1;
    F.insert(1);

    int ans = 0;
    while (true) {
        if (Q.empty()) {
            break;
        }

        for (int w = 1; w <= n; ++w) {
            if (a[v][w] != -1) {
                auto it = F.find(w);
                if (it == F.end() && a[v][w] < C[w]) {
                    C[w] = a[v][w];
                }
            }
        }

        int cost = INF;
        int vertex = -1;
        for (int w = 1; w <= n; ++w) {
            auto it = F.find(w);
            if (it == F.end() && C[w] < cost) {
                cost = C[w];
                vertex = w;
            }
        }

        if (vertex == -1) {
            terminate();
        }

        Q.erase(vertex);
        F.insert(vertex);
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
