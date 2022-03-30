// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
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
using std::queue;
using std::stack;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::abs;
using std::sort;

// キーワード: 拡張BFS・ダイクストラ

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

const int INF = 1e9+7;

enum Direction {
    East = 0,
    South = 1,
    West = 2,
    North = 3
};

template <class T>
bool min(T &a, const T b) {
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

class Program {
private:
    int H, W;
    int rs, cs, rt, ct;
    vector<string> S;

    vector<vector<vector<int>>> dist;

public:

    Program() {
        cin >> H >> W;
        assert(H >= 2);
        assert(H <= 1000);
        assert(W >= 2);
        assert(W <= 1000);

        cin >> rs >> cs;
        assert(rs >= 1);
        assert(rs <= H);
        rs--;
        assert(cs >= 1);
        assert(cs <= W);
        cs--;

        cin >> rt >> ct;
        assert(rt >= 1);
        assert(rt <= H);
        rt--;
        assert(ct >= 1);
        assert(ct <= W);
        ct--;

        S.resize(H);
        rep(i, 0, H) cin >> S[i];

        dist.resize(H, vector<vector<int>>(W, vector<int>(4, INF)));
        for (auto d : {East, South, West, North}) dist[rs][cs][d] = 0;
    }

    void solve() {
        deque<tuple<int, int, int>> deq;

        for (auto d : {East, South, West, North}) deq.push_back({rs, cs, d});

        while (!deq.empty()) {
            auto [r, c, d] = deq.front();
            // printf("%d,%d,%d,%d\n", r, c, d, dist[r][c][d]);
            deq.pop_front();

            int cost = dist[r][c][d] + 1;

            if (c+1 < W && S[r][c+1] == '.') {
                // East
                if (d != East) {
                    if (dist[r][c+1][East] > dist[r][c][d] + 1) {
                        dist[r][c+1][East] = dist[r][c][d] + 1;
                        deq.push_back({r, c+1, East});
                    }
                } else {
                    if (dist[r][c+1][d] > dist[r][c][d]) {
                        dist[r][c+1][d] = dist[r][c][d];
                        deq.push_front({r, c+1, East});
                    }
                }

            }

            if (r+1 < H && S[r+1][c] == '.') {
                // South
                if (d != South) {
                    if (dist[r+1][c][South] > dist[r][c][d] + 1) {
                        dist[r+1][c][South] = dist[r][c][d] + 1;
                        deq.push_back({r+1, c, South});
                    }
                } else {
                    if (dist[r+1][c][d] > dist[r][c][d]) {
                        dist[r+1][c][d] = dist[r][c][d];
                        deq.push_front({r+1, c, South});
                    }
                }

            }

            if (c-1 >= 0 && S[r][c-1] == '.') {
                // West
                if (d != West) {
                    if (dist[r][c-1][West] > dist[r][c][d] + 1) {
                        dist[r][c-1][West] = dist[r][c][d] + 1;
                        deq.push_back({r, c-1, West});
                    }
                } else {
                    if (dist[r][c-1][d] > dist[r][c][d]) {
                        dist[r][c-1][d] = dist[r][c][d];
                        deq.push_front({r, c-1, West});
                    }
                }

            }

            if (r-1 >= 0 && S[r-1][c] == '.') {
                // North
                if (d != North) {
                    if (dist[r-1][c][North] > dist[r][c][d] + 1) {
                        dist[r-1][c][North] = dist[r][c][d] + 1;
                        deq.push_back({r-1, c, North});
                    }
                } else {
                    if (dist[r-1][c][d] > dist[r][c][d]) {
                        dist[r-1][c][d] = dist[r][c][d];
                        deq.push_front({r-1, c, North});
                    }
                }

            }
        }

        int ans = INF;
        for (auto d : {East, South, West, North}) {
            min(ans, dist[rt][ct][d]);
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
