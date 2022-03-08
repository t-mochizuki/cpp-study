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

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

    int n;
    vector<long> x, y;

    long abs(long x) {
        if (x >= 0) return x;
        else return -x;
    }

    // S=1/2|ad-bc|
    // (0, 0), (a, b), (c, d)
    long triangle(int i, int j, int k) {
        return abs((x[i]-x[k])*(y[j]-y[k]) - (y[i]-y[k])*(x[j]-x[k]));
    }

public:

    Program() {
        cin >> n;
        assert(n >= 3);
        assert(n <= 300);

        x.resize(n);
        y.resize(n);

        rep(i, 0, n) {
            cin >> x[i] >> y[i];
        }
    }

    void solve() {
        long ans = 0;
        rep(i, 0, n) rep(j, i+1, n) rep(k, j+1, n) {
            if (triangle(i, j, k) != 0) {
                ans++;
            }
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
        Program p;
        p.solve();
    }
#else
    Program p;
    p.solve();
#endif

    return 0;
}
