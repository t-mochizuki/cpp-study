#ifndef BFS
#define BFS 1

#include <vector>
#include <queue>

using std::vector;
using std::queue;

using Graph = vector<vector<int>>;

namespace nutshell {

class BreadthFirstSearch {
public:

    vector<bool> seen;

    BreadthFirstSearch(int N) {
        seen.assign(N, false);
    }

    void search(Graph &g, int s) {
        queue<int> que;

        seen[s] = 0;
        que.push(s);

        while (!que.empty()) {
            int u = que.front(); que.pop();
            for (auto v : g[u]) {
                if (seen[v]) continue;

                seen[v] = true;
                que.push(v);
            }
        }
    }

};

} // namespace nutshell

#endif // BFS
