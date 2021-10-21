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
using std::min;

// キーワード: 工夫した全探索

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    long N, A, B, C;

public:

    Problem() {
        cin >> N >> A >> B >> C;
    }

    void solve() {
        long y = 10000;
        long L = 9999;
        for (long c = 0; c <= L; ++c) {
            for (long b = 0; c+b <= L; ++b) {
                long a = (N - C*c - B*b) / A;
                if (a < 0) continue;
                if (a+b+c > L) continue;

                long r = (N - C*c - B*b) % A;
                if (r == 0) {
                    y = min(y, a+b+c);
                }
            }
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
