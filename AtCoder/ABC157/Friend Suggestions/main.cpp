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

enum Relation { Friend, Block };

struct Edge {
    int to;
    Relation rel;
};

vector<bool> dfs(Graph G, int N, int v) {
    vector<bool> visited; visited.assign(N, false);

    stack<int> sta;

    visited[v] = true;
    sta.push(v);

    while (sta.empty() == false) {
        int u = sta.top(); sta.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            int x = G[u][i];
            if (visited[x] == false) {
                visited[x] = true;
                sta.push(x);
            }
        }
    }

    return visited;
}

void solve() {
    int N, M, K; cin >> N >> M >> K;

    Graph Friend(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        Friend[a].push_back(b);
        Friend[b].push_back(a);
    }

    Graph Block(N);
    for (int i = 0; i < K; ++i) {
        int c, d; cin >> c >> d; --c; --d;
        Block[c].push_back(d);
        Block[d].push_back(c);
    }

    for (int v = 0; v < N; ++v) {
        vector<bool> visited = dfs(Friend, N, v);

        visited[v] = false;

        vector<int> friends = Friend[v];
        for (decltype(friends)::iterator it = friends.begin(); it != friends.end(); ++it) {
            visited[*it] = false;
        }

        vector<int> blocks = Block[v];
        for (decltype(blocks)::iterator it = blocks.begin(); it != blocks.end(); ++it) {
            visited[*it] = false;
        }

        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            if (visited[i]) {
                cnt++;
            }
        }

        if (v == 0) {
            cout << cnt;
        } else {
            cout << " " << cnt;
        }
    }
    cout << endl;
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
