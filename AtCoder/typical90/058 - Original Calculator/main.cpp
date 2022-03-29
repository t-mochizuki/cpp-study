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

// キーワード: 周期性を考える

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

    long n, k;
    vector<bool> seen;
    vector<int> dist;

    long z(long x) {
        // 各桁の和を求める
        long y = 0, tmp = x;
        while (tmp > 0) {
            y += tmp % 10;
            tmp /= 10;
        }

        return (x + y) % 100000;
    }

public:

    Program() {
        cin >> n >> k;
        assert(n < 100000);

        seen.assign(100000, false);
        seen[n] = true;

        dist.assign(100000, -1);
        dist[n] = 0;
    }


    void solve() {
        // 0: 処理後も0
        if (n == 0) {
            cout << 0 << endl;
            return ;
        }

        if (k < 100000) {
            long x = n;
            rep(i, 0, k) {
                x = z(x);
            }
            cout << x << endl;
        } else {
            long x = n;
            long cnt = 0, lastCnt = 0;
            rep(i, 0, 100000) {
                x = z(x);
                if (seen[x]) {
                    // サイクルの2周目
                    break;
                }
                seen[x] = true;
                cnt++;
                dist[x] = cnt;
                lastCnt = cnt;
            }

            // サイクルの長さを求める
            long cycle = lastCnt + 1 - dist[x];

            // 始点からサイクル入口に移動する
            k -= dist[x];

            k %= cycle;

            rep(i, 0, k) {
                x = z(x);
            }
            cout << x << endl;

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
