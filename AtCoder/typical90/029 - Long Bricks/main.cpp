// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::max;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int W, N;

public:

    Problem() {
        cin >> W >> N;
        assert(2 <= W);
        assert(W <= 500000);
        assert(1 <= N);
        assert(N <= 250000);

        if (W > 9000 || N > 9000) {
            terminate();
        }
    }

    void solve() {
        vector<int> height;
        height.assign(W+1, 0);

        rep(x, 0, N) {
            int L, R; cin >> L >> R;

            assert(1 <= L);
            assert(L <= W);
            assert(1 <= R);
            assert(R <= W);
            assert(L <= R);

            int maximum = 0;
            rep(i, L, R+1) {
                maximum = max(height[i], maximum);
            }
            maximum++;

            cout << maximum << endl;

            rep(i, L, R+1) height[i] = maximum;
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
