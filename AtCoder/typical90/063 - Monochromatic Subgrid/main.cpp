// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::string;
using std::pair;
using std::map;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::abs;
using std::sort;

// キーワード: 変な制約に着目する/状態数が少ない変量を全探索

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

    int H, W;
    vector<vector<int>> P;

public:

    Program() {
        cin >> H >> W;
        assert(H <= 8);
        assert(W <= 10000);

        P.resize(H, vector<int>(W));
        rep(i, 0, H) rep(j, 0, W) cin >> P[i][j];
    }

    void solve() {
        // 0: 行を選ばないので省略する
        int ans = 0;
        rep(pat, 1, (1<<H)) {
            map<int, int> m;

            rep(j, 0, W) {
                // すべて同じ整数か
                bool first = true, every = true;
                long x = 0;
                rep(i, 0, H) {
                    if (bit(pat, i) == 1) {
                        if (first) {
                            first = false;
                            x = P[i][j];
                        } else {
                            if (x != P[i][j]) {
                                every = false;
                                break;
                            }
                        }
                    }
                }

                if (every) {
                    if (m.count(x) == 1) {
                        m[x]++;
                    } else {
                        m[x] = 1;
                    }
                }
            }

            // 選んだ行数を求める
            int cnt = 0;
            rep(i, 0, H) {
                if (bit(pat, i) == 1) {
                    cnt++;
                }
            }

            // ビットを可視化する
            string s;
            for (int i = H-1; i >= 0; --i) {
                if (bit(pat, i) == 1) {
                    s.append("1", 1);
                } else {
                    s.append("0", 1);
                }
            }

            for (auto [k, v] : m) {
                // printf("pat: %s, cnt: %d, %d, %d\n", s.c_str(), cnt, k, v);
                max(ans, cnt * v);
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
