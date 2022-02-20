// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::sort;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    const int MOD = 1e9+7;
    int N;
    vector<int> C;

public:
    Problem() {
        cin >> N;

        C.resize(N);
        rep(i, 0, N) cin >> C[i];
        sort(C.begin(), C.end());
    }

    void solve() {
        long ans = 1;
        rep(i, 0, N) {
            ans *= C[i] - i;

            ans %= MOD;
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
        Problem p;
        p.solve();
    }
#else
    Problem p;
    p.solve();
#endif

    return 0;
}
