// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::max;
using std::sort;
using std::map;
using std::make_pair;

// キーワード: 「座標圧縮」で効率化

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int W, N;
    vector<int> L, R;
    map<int, int> zip;

public:

    Problem() {
        cin >> W >> N;
        assert(2 <= W);
        assert(W <= 500000);
        assert(1 <= N);
        assert(N <= 250000);

        L.resize(N);
        R.resize(N);
        rep(i, 0, N) {
            cin >> L[i] >> R[i];

            assert(1 <= L[i]);
            assert(W >= L[i]);
            assert(1 <= R[i]);
            assert(W >= R[i]);
            assert(L[i] <= R[i]);
        }

        rep(i, 0, N) {
            if (zip.find(L[i]) == zip.end()) {
                zip.insert(make_pair(L[i], 1));
            }
            if (zip.find(R[i]) == zip.end()) {
                zip.insert(make_pair(R[i], 1));
            }
        }

        int num = 1;
        for (auto it = zip.begin(); it != zip.end(); ++it) {
            it->second = num;
            num++;
        }

        if (N > 9000) {
            terminate();
        }
    }

    void solve() {
        vector<int> height;
        height.assign(W+1, 0);

        rep(i, 0, N) {
            int maximum = 0;
            rep(j, zip[L[i]], zip[R[i]]+1) {
                maximum = max(height[j], maximum);
            }
            maximum++;

            cout << maximum << endl;

            rep(j, zip[L[i]], zip[R[i]]+1) height[j] = maximum;
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
