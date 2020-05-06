#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::sort;

struct Point {
    int p, q;

    bool operator<(const Point& rhs) const {
        return p < rhs.p;
    }
};

void solve() {
    int W, H, N; cin >> W >> H >> N;

    Point XY[N];
    for (int i = 0; i < N; ++i) {
        int X, Y; cin >> X >> Y;
        XY[i] = {X, Y};
    }

    sort(XY, XY + N);

    if (N > 8 || W > 80 || H > 80) {
        terminate();
    } else {
        for (int i = 0; i < N; ++i) {
            printf("X[%d]=%d, Y[%d]=%d\n", i, XY[i].p, i, XY[i].q);
        }
    }
}

int main() {
    std::ifstream in("AtCoder/ABC008/金塊ゲーム.input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }

    return 0;
}
