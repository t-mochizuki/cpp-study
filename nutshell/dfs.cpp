/*
g++ -std=c++14 -c dfs.cpp
 */
#ifndef DFS
#define DFS 1

#include <vector>
#include <stack>

using std::vector;
using std::stack;

using Graph = vector<vector<int>>;

namespace nutshell {

class DepthFirstSearch {
public:

    vector<bool> seen;

    DepthFirstSearch(int N) {
        seen.assign(N, false);
    }

    void search(Graph &g, int s) {
        stack<int> st;

        seen[s] = true;
        st.push(s);

        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (auto v : g[u]) {
                if (seen[v]) continue;

                seen[v] = true;
                st.push(v);
            }
        }
    }

};

} // namespace nutshell

#endif // DFS
