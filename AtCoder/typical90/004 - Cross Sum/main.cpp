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

class Problem {
private:

    int H, W;
    vector<vector<int>> a;
    vector<int> vertical, horizontal;

public:
    Problem() {
        cin >> H >> W;

        a.assign(H, vector<int>(W, 0));
        horizontal.assign(H, 0);
        vertical.assign(W, 0);
        rep(i, 0, H) {
            rep(j, 0, W) {
                cin >> a[i][j];
                horizontal[i] += a[i][j];
                vertical[j] += a[i][j];
            }
        }

    }

    void solve() {
        rep(i, 0, H) {
            rep(j, 0, W) {
                int b = horizontal[i] + vertical[j] - a[i][j];
                if (j == 0) cout << b;
                else cout << " " << b;
            }
            cout << endl;
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
