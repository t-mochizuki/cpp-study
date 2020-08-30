#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::stack;

typedef vector<vector<int> > Graph;
typedef vector<int> Edges;

int dfs(Graph G, int N, int v) {
    vector<bool> visited; visited.assign(N, false);

    stack<int> sta;

    visited[v] = true;
    sta.push(v);

    while (sta.empty() == false) {
        int u = sta.top(); sta.pop();
        for (int x : G[u]) {
            if (visited[x] == false) {
                visited[x] = true;
                sta.push(x);
            }
        }
    }

    cout << v << ": ";
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (visited[i]) {
            if (cnt == 0) {
                cout << i;
            } else {
                cout << " " << i;
            }
            cnt++;
        }
    }
    cout << endl;

    return cnt;
}

void solve() {
    int N, M; cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        // G[b].push_back(a);
    }

    // for (int i = 0; i < N; ++i) {
    //     cout << i << ": ";
    //     for (Edges::iterator it = G[i].begin(); it != G[i].end(); ++it) {
    //         if (it == G[i].begin()) cout << *it;
    //         else cout << " " << *it;
    //     }
    //     cout << endl;
    // }

    for (int v = 0; v < N; ++v) {
        dfs(G, N, v);
    }

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
