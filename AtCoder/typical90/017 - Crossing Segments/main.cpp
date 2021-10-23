// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

// キーワード: 条件を式で表してみる

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int N, M;
    vector<int> L, R;

public:

    Problem() {
        cin >> N >> M;

        L.resize(M);
        R.resize(M);
        rep(i, 0, M) cin >> L[i] >> R[i];

        if (M > 1000) {
            terminate();
        }
    }

    void solve() {
        long y = 0;

        rep(s, 0, M) rep(t, s+1, M) {
            if (L[s] < L[t] && L[t] < R[s] && R[s] < R[t]) y++;
            if (L[t] < L[s] && L[s] < R[t] && R[t] < R[s]) y++;
        }

        cout << y << endl;
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
