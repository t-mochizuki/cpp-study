// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <tuple>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::string;
using std::map;
using std::pair;
using std::deque;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::abs;
using std::sort;

// キーワード: DPをセグメント木で高速化
// RMQ, スライド最小値

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

const long INF = 1000000007L;

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

    int w, n;
    vector<tuple<int, int, long>> a;
    vector<long> state, next;

public:

    Program() {
        cin >> w >> n;
        a.resize(n);
        for (auto& [l, r, v] : a) {
            cin >> l >> r >> v;
        }

        state.assign(w+1, -INF);
        state[0] = 0L;

        next.assign(w+1, -INF);
        next[0] = 0L;

        assert(w <= 5000);
    }

    void solve() {
        rep(i, 0, n) {
            auto [l, r, v] = a[i];

            // 基本的に料理を作ることができるならば料理を作る
            rep(j, 0, w+1) {
                for (int k = l; k <= r; ++k) {
                    if (j+k <= w) {
                        // 少なくとも香辛料がk[mg]ある
                        if (state[j] + v > next[j+k]) {
                            next[j+k] = state[j] + v;
                        } else {
                            // 料理iを作らないほうが作る料理の価値の合計が大きくなる
                        }
                    }
                }
            }

            state = next;
        }

        if (state[w] >= 0) {
            cout << state[w] << endl;
        } else {
            cout << -1 << endl;
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
