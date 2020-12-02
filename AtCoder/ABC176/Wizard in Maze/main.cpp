#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <deque>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::map;
using std::make_pair;
using std::sort;
using std::to_string;
using std::lower_bound;
using std::distance;
using std::set;
using std::deque;

const int INF = 1L << 30;

class Point {
public:

    int _h = -1;
    int _w = -1;

    Point() {}
    Point(int h, int w): _h(h), _w(w) {}
};

template<class T> inline T abs(T X) {
    return X > 0 ? X : -X;
}

template<class T> inline T manhattan(T X, T Y) {
    return abs(X) + abs(Y);
}

void solve() {
    int H, W;
    cin >> H >> W;

    int Ch, Cw;
    cin >> Ch >> Cw;
    Ch--; Cw--;

    int Dh, Dw;
    cin >> Dh >> Dw;
    Dh--; Dw--;

    string S[H];
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    int dist[H][W];
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            dist[i][j] = INF;
        }
    }
    dist[Ch][Cw] = 0;

    deque<Point> deq;
    deq.push_front(Point(Ch, Cw));

    while (!deq.empty()) {
        Point u = deq.front(); deq.pop_front();

        for (int h = u._h - 2; h <= u._h + 2; ++h) {
            for (int w = u._w - 2; w <= u._w + 2; ++w) {
                if ((h == u._h && w == u._w)
                || (h < 0)
                || (w < 0)
                || (h >= H)
                || (w >= W)) {
                    continue;
                }

                if (S[h][w] == '.') {
                    if (manhattan(h - u._h, w - u._w) == 1) {
                        if (dist[h][w] > dist[u._h][u._w]) {
                            dist[h][w] = dist[u._h][u._w];
                            deq.push_front(Point(h, w));
                        }
                    } else {
                        if (dist[h][w] > dist[u._h][u._w] + 1) {
                            dist[h][w] = dist[u._h][u._w] + 1;
                            deq.push_back(Point(h, w));
                        }
                    }
                }
            }
        }
    }

    if (dist[Dh][Dw] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[Dh][Dw] << endl;
    }
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
