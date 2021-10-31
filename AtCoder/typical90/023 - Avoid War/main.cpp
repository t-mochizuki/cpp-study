// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::string;
using std::tuple;
using std::make_tuple;
using std::tie;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int H, W;
    vector<tuple<int, int>> C;

    void debug_C() {
        for (auto& t : C) {
            int i, j;
            tie(i, j) = t;
            cout << i << " " << j << endl;
        }
        cout << endl;
    }

public:

    Problem() {
        cin >> H >> W;

        rep(i, 0, H) {
            string s; cin >> s;
            rep(j, 0, W) {
                if (s[j] == '.') C.push_back(make_tuple(i, j));
            }
        }

        if (H > 4 || W > 4) {
            terminate();
        }
    }

    void solve() {
        long ans = 0;
        for (int /*bit*/ pat/*tern*/ = (1<<C.size())-1; pat >= 0; --pat) {
            vector<vector<bool>> grid;
            grid.assign(H, vector<bool>(W, false));

            bool ok = true;
            rep(k, 0, C.size()) {
                if (ok == false) break;

                if (bit(pat, k) == 1) {
                    int i, j;
                    tie(i, j) = C[k];
                    rep(ii, i-1, i+1) rep(jj, j-1, j+1) {
                        if (ok == false) break;

                        if (ii >= 0 && ii < H && jj >= 0 && jj < W) {
                            if (grid[ii][jj]) {
                                ok = false;
                                break;
                            } else {
                                grid[ii][jj] = true;
                            }
                        }
                    }
                }
            }

            if (ok) {
                // cout << "pat:" << pat << endl;
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
        Problem p;
        p.solve();
    }
#else
    Problem p;
    p.solve();
#endif

    return 0;
}
