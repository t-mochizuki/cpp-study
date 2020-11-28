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
    int weight[n][n];
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            weight[u][v] = INF;
        }
    }

    for (int i = 0; i < n; ++i) {
        int u; cin >> u;
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            int v; cin >> v;
            cin >> weight[u][v];
        }
    }

    // for (int u = 0; u < n; ++u) {
    //     for (int v = 0; v < n; ++v) {
    //         if (v == n - 1) {
    //             cout << weight[u][v] << endl;
    //         } else {
    //             cout << weight[u][v] << " ";
    //         }
    //     }
    // }

    int dist[n];
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (i == s) {
            dist[i] = 0;
        } else {
            dist[i] = INF;
        }
    }

    int parent[n];
    for (int i = 0; i < n; ++i) {
        parent[i] = -1;
    }

    set<int> T;

    while (true) {
        int u = -1;
        int cost = INF;
        for (int v = 0; v < n; ++v) {
            if (T.find(v) != T.end()) {
                continue;
            }
            if (dist[v] < cost) {
                cost = dist[v];
                u = v;
            }
        }

        if (u == -1) {
            break;
        }

        T.insert(u);

        for (int v = 0; v < n; ++v) {
            if (weight[u][v] == INF) {
                continue;
            }
            if (dist[v] > dist[u] + weight[u][v]) {
                dist[v] = dist[u] + weight[u][v];
                parent[v] = u;
            }
        }
    }

    for (int v = 0; v < n; ++v) {
        cout << v << " " << dist[v] << endl;
    }

    // for (int v = 0; v < n; ++v) {
    //     if (v == n - 1) {
    //         cout << dist[v] << endl;
    //     } else {
    //         cout << dist[v] << " ";
    //     }
    // }

    // for (int v = 0; v < n; ++v) {
    //     if (v == n - 1) {
    //         cout << parent[v] << endl;
    //     } else {
    //         cout << parent[v] << " ";
    //     }
    // }
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
