#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <set>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::map;
using std::make_pair;
using std::pair;
using std::sort;
using std::to_string;
using std::lower_bound;
using std::distance;
using std::deque;
using std::set;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

void solve() {
    int H, W, M; cin >> H >> W >> M;
    int h[M], w[M];
    for (int i = 0; i < M; ++i) {
        cin >> h[i] >> w[i];
        h[i]--; w[i]--;
    }

    vector<int> R, C;
    R.resize(H, 0);
    C.resize(W, 0);
    for (int i = 0; i < M; ++i) {
        R[h[i]]++;
        C[w[i]]++;
    }

    int maxR = 0;
    for (int i = 0; i < H; ++i) {
        maxR = max(maxR, R[i]);
    }
    int maxC = 0;
    for (int i = 0; i < W; ++i) {
        maxC = max(maxC, C[i]);
    }

    vector<int> iR, iC;
    for (int i = 0; i < H; ++i) {
        if (R[i] == maxR) {
            iR.push_back(i);
        }
    }
    for (int i = 0; i < W; ++i) {
        if (C[i] == maxC) {
            iC.push_back(i);
        }
    }

    set<pair<int, int>> s;
    for (int i = 0; i < M; ++i) {
        s.insert({h[i], w[i]});
    }

    int ans = maxR + maxC - 1;
    for (auto r : iR) for (auto c : iC) {
        if (s.find({r, c}) == s.end()) {
            ans = maxR + maxC;
            break;
        }
    }

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
