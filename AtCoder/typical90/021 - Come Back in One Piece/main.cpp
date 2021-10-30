// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::stack;
using std::map;
using std::make_pair;

// キーワード: 強連結成分分解(SCC)をしよう

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int N, M;
    map<int, vector<int>> E;
    map<int, vector<int>> R;

    vector<bool> visited;
    vector<int> assigned;
    stack<int> L;

    void debug_L() {
        for (int x = 1; x <= N; ++x) {
            if (L.empty()) break;

            cout << L.top() << endl; L.pop();
        }
    }

    void debug_assigned() {
        for (int i = 1; i <= N; ++i) {
            if (i == 1) cout << assigned[i];
            else cout << " " << assigned[i];
        }
        cout << endl;
    }

public:

    Problem() {
        cin >> N >> M;

        for (int x = 1; x <= M; ++x) {
            int a, b; cin >> a >> b;
            if (E.find(a) == E.end()) {
                E.insert(make_pair(a, vector<int>(1, b)));
            } else {
                E[a].push_back(b);
            }

            if (R.find(b) == R.end()) {
                R.insert(make_pair(b, vector<int>(1, a)));
            } else {
                R[b].push_back(a);
            }
        }

        visited.assign(N+1, false);
        assigned.assign(N+1, 0);
    }

    void visit(int from) {
        if (visited[from]) return ;

        visited[from] = true;
        L.push(from);

        for (auto to : E[from]) {
            visit(to);
        }
    }

    void assign(int from, int root) {
        if (assigned[from] != 0) return ;

        assigned[from] = root;

        for (auto to : R[from]) {
            assign(to, root);
        }
    }

    // Kosaraju's_algorithm
    void solve() {
        if (M == 1) {
            cout << 0 << endl;
            return ;
        }

        for (int x = 1; x <= N; ++x) {
            assert(visited[x] == false);
            assert(assigned[x] == 0);
        }
        assert(L.empty() == true);

        for (int i = 1; i <= N; ++i) visit(i);

        assert(L.size() == N);

        while(true) {
            if (L.empty()) break;

            int from = L.top(); L.pop();
            assign(from, from);
        }

        map<int, long> tmp;
        for (int i = 1; i <= N; ++i) {
            if (tmp.find(assigned[i]) == tmp.end()) {
                tmp.insert(make_pair(assigned[i], 1));
            } else {
                tmp[assigned[i]]++;
            }
        }

        long ans = 0;
        for (auto p : tmp) {
            ans += (p.second*(p.second-1))/2;
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
