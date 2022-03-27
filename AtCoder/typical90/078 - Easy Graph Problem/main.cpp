// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::sort;
using std::upper_bound;
using std::distance;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

    int n, m;
    vector<vector<int>> edge;

public:

    Program() {
        cin >> n >> m;

        edge.resize(n);
        rep(i, 0, m) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        rep(i, 0, n) {
            sort(edge[i].begin(), edge[i].end());
        }
    }

    void solve() {
        int ans = 0;
        rep(u, 0, n) {
            auto it = upper_bound(edge[u].begin(), edge[u].end(), u);
            if (distance(edge[u].begin(), it) == 1) {
                ans++;
            }
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
        Program p;
        p.solve();
    }
#else
    Program p;
    p.solve();
#endif

    return 0;
}
