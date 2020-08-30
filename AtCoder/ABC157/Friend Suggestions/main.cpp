#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::stack;
using std::map;
using std::make_pair;

typedef vector<vector<int> > Graph;
typedef int GraphId;

void dfs(Graph &G, GraphId &id, vector<GraphId> &visited, map<GraphId, int> &m, int v) {
    if (visited[v] != -1) {
        return ;
    }

    id++;

    stack<int> sta;

    visited[v] = id;
    sta.push(v);
    m.insert(make_pair(id, 1));

    while (sta.empty() == false) {
        int u = sta.top(); sta.pop();
        for (int x : G[u]) {
            if (visited[x] == -1) {
                visited[x] = id;
                sta.push(x);
                m[id]++;
            }
        }
    }

    return ;
}

void solve() {
    int N, M, K; cin >> N >> M >> K;

    Graph Friend(N);
    vector<int> num(N, 0);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        Friend[a].emplace_back(b);
        Friend[b].emplace_back(a);
        num[a]++;
        num[b]++;
    }

    Graph Block(N);
    for (int i = 0; i < K; ++i) {
        int c, d; cin >> c >> d; --c; --d;
        Block[c].emplace_back(d);
        Block[d].emplace_back(c);
    }

    vector<GraphId> visited; visited.assign(N, -1);
    GraphId id = 0;
    map<GraphId, int> m;
    for (int v = 0; v < N; ++v) {
        dfs(Friend, id, visited, m, v);

        GraphId gid = visited[v];
        int cnt = m[gid] - num[v] - 1;

        vector<int> blocks = Block[v];
        for (int x : blocks) {
            if (gid == visited[x]) {
                cnt--;
            }
        }

        if (v != N - 1) {
            cout << cnt << " ";
        } else {
            cout << cnt << endl;
        }
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
