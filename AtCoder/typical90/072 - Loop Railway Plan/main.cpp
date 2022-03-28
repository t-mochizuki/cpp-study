// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::string;

// キーワード: "何通りか"の感覚/バックトラック

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

template <class T>
bool max(T &a, const T b) {
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

class Program {
private:

    int h, w;
    vector<string> c;
    vector<vector<bool>> seen;

public:

    Program() {
        cin >> h >> w;
        c.resize(h);
        rep(i, 0, h) cin >> c[i];

        seen.assign(h, vector<bool>(w, false));
    }

    int search(pair<int, int> start, pair<int, int> current, int k) {
        auto [si, sj] = start;
        auto [i, j] = current;

        if (i < 0) return -1;
        if (i >= h) return -1;
        if (j < 0) return -1;
        if (j >= w) return -1;

        if (seen[i][j]) {
            // 条件2を満たさない
            return -1;
        }

        if (c[i][j] == '#') {
            // 条件3を満たさない
            return -1;
        }

        if (k >= 3 && sj == j && si == i) {
            // 終点
            return k;
        }

        seen[i][j] = true;

        int ret = -2;
        auto ps = {
            pair<int, int>(i, j+1),
            pair<int, int>(i+1, j),
            pair<int, int>(i, j-1),
            pair<int, int>(i-1, j)
        };
        for (auto p : ps) {
            max(ret, search(start, p, k+1));
        }

        seen[i][j] = false;

        return ret;
    }

    void solve() {

        int ans = -2;
        rep(i, 0, h) {
            rep(j, 0, w) {
                if (c[i][j] == '.') {
                    max(ans, search({i, j}, {i, j-1}, 1));
                    max(ans, search({i, j}, {i-1, j}, 1));
                    max(ans, search({i, j}, {i, j+1}, 1));
                    max(ans, search({i, j}, {i+1, j}, 1));
                }
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
