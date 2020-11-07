#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

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

// TODO: WA

const int INF = 1 << 30;

class Box {
public:
    int m_w{INF};
    int m_h{INF};

    Box() {}
    Box(int w, int h)
        : m_w(w), m_h(h) {}
    bool operator<(const Box& rhs) const {
        return m_w < rhs.m_w && m_h < rhs.m_h;
    }
};

void solve() {
    int n; cin >> n;
    Box boxes[n];
    int w, h;
    for (int i = 0; i < n; ++i) {
        cin >> w >> h;
        Box b(w, h);
        boxes[i]=b;
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << boxes[i].w << " " << boxes[i].h << endl;
    // }

    sort(boxes,boxes+n);

    Box dp[n+1];
    for (int i = 0; i < n+1; ++i) {
        Box b; dp[i]=b;
    }

    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(dp, dp+n+1, boxes[i]);
        int j = distance(dp,it);
        dp[j]=boxes[i];
    }

    Box b;
    auto it = lower_bound(dp, dp+n+1, b);
    int ans = distance(dp,it);
    cout << ans << endl;
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
