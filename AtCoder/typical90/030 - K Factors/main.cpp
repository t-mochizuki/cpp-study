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

// キーワード: 素因数列挙の計算量はO(N log log N)

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int N, K;
    vector<int> C;

    void debug() {
        for (int i = 2; i <= N; ++i) {
            cout << i << ":" << C[i] << endl;
        }
    }

public:

    Problem() {
        cin >> N >> K;
        assert(N >= 2);
        assert(N <= (int)1e7);
        assert(K >= 1);
        assert(K <= 8);

        C.assign(N+1, 0);
    }

    void solve() {
        for (int i = 2; i <= N; ++i) {
            if (C[i] != 0) continue;

            for (int j = i; j <= N; j += i) {
                C[j] += 1;
            }
        }

        int cnt = 0;
        for (int i = 2; i <= N; ++i) {
            if (C[i] >= K) cnt++;
        }

        cout << cnt << endl;
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
