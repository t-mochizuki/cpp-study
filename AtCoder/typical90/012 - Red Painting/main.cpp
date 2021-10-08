// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)


class DisjointSet {
private:

    void swap(int &A, int &B) {
        int tmp = A;
        A = B;
        B = tmp;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
            return parent[x];
        } else {
            return x;
        }
    }

    // union by rank
    void link(int x, int y) {
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

public:

    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        rank.resize(n, 0);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);

        if (rx == ry) {
            return ;
        }

        link(rx, ry);
    }
};

class Problem {
private:

    int H, W, Q;
    vector<vector<bool>> grid;

public:
    Problem() {
        cin >> H >> W >> Q;

        grid.assign(H, vector<bool>(W, false));
    }

    void debug() {
        rep(r, 0, H) {
            rep(c, 0, W) {
                if (c == 0) cout << grid[r][c];
                else cout << "," << grid[r][c];
            }
            cout << endl;
        }
        cout << endl;
    }

    void solve() {
        DisjointSet ds(H*W);

        rep(i, 0, Q) {
            int t; cin >> t;
            if (t == 1) {
                int r, c; cin >> r >> c;
                r--; c--;

                grid[r][c] = true;

                if ((c-1 >= 0) && grid[r][c-1]) {
                    ds.merge(c+r*W, c-1+r*W);
                }
                if ((c+1 < W) && grid[r][c+1]) {
                    ds.merge(c+r*W, c+1+r*W);
                }
                if ((r-1 >= 0) && grid[r-1][c]) {
                    ds.merge(c+r*W, c+(r-1)*W);
                }
                if ((r+1 < H) && grid[r+1][c]) {
                    ds.merge(c+r*W, c+(r+1)*W);
                }

                // debug();
            } else if (t == 2) {
                int ra, ca; cin >> ra >> ca;
                ra--; ca--;
                int rb, cb; cin >> rb >> cb;
                rb--; cb--;

                if (grid[ra][ca] && grid[rb][cb] && ds.same(ra*W+ca, rb*W+cb)) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            } else {
                terminate();
            }
        }
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
