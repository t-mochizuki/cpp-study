// g++ -std=c++17 -D DEV=1 main.cpp
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
using std::abs;

// キーワード: 操作順序によらない

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

    int H, W;
    vector<vector<int>> a, b;

public:

    Program() {
        cin >> H >> W;

        a.resize(H, vector<int>(W, -1));
        rep(i, 0, H) rep(j, 0, W) cin >> a[i][j];

        b.resize(H, vector<int>(W, -1));
        rep(i, 0, H) rep(j, 0, W) cin >> b[i][j];
    }

    void solve() {
        long ans = 0;
        rep(i, 0, H-1) {
            rep(j, 0, W-1) {
                if (a[i][j] != b[i][j]) {
                    int c = b[i][j] - a[i][j];
                    a[i][j] += c;
                    a[i][j+1] += c;
                    a[i+1][j] += c;
                    a[i+1][j+1] += c;
                    ans += abs(c);
                }
            }
        }

        bool ok = true;
        rep(i, 0, H) {
            if (a[i][W-1] != b[i][W-1]) {
                ok = false;
                break;
            }
        }

        rep(j, 0, W) {
            if (a[H-1][j] != b[H-1][j]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << "Yes" << endl;
            cout << ans << endl;
        } else {
            cout << "No" << endl;
        }
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
