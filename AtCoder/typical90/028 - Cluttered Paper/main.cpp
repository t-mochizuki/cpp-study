// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

// キーワード: 領域加算は二次元いすも法

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int N;
    vector<vector<int>> grid;

    void debug() {
        rep(y, 0, 10) {
            rep(x, 0, 10) {
                if (x == 1) cout << grid[y][x];
                else cout << " " << grid[y][x];
            }
            cout << endl;
        }
        cout << endl;
    }

public:

    Problem() {
        cin >> N;

        assert(1 <= N);
        assert(N <= 100000);

        grid.assign(1001, vector<int>(1001, 0));
        rep(i, 0, N) {
            int lx, ly, rx, ry;
            cin >> lx >> ly >> rx >> ry;

            assert(0 <= lx);
            assert(lx <= 1000);
            assert(0 <= rx);
            assert(rx <= 1000);
            assert(lx < rx);

            assert(0 <= ly);
            assert(ly <= 1000);
            assert(0 <= ry);
            assert(ry <= 1000);
            assert(ly < ry);

            grid[ly][lx] += 1;
            grid[ly][rx] -= 1;
            grid[ry][lx] -= 1;
            grid[ry][rx] += 1;
        }
    }

    void solve() {
        // debug();

        for (int y = 0; y <= 1000; ++y) {
            for (int x = 0; x <= 1000; ++x) {
                if (x != 0) grid[y][x] += grid[y][x-1];
            }
        }

        for (int x = 0; x <= 1000; ++x) {
            for (int y = 0; y <= 1000; ++y) {
                if (y != 0) grid[y][x] += grid[y-1][x];
            }
        }

        // debug();

        vector<int> ans;
        ans.assign(N+1, 0);
        for (int x = 0; x <= 1000; ++x) {
            for (int y = 0; y <= 1000; ++y) {
                ans[grid[y][x]]++;
            }
        }

        rep(i, 1, N+1) {
            cout << ans[i] << endl;
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
