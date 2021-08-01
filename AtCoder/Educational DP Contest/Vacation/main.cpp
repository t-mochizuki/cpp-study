// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class Problem {
private:

    int N;
    vector<int> a, b, c;
    vector<long> dpa, dpb, dpc;

public:
    Problem() {
        cin >> N;

        a.assign(N, 0);
        b.assign(N, 0);
        c.assign(N, 0);
        rep(i, N) cin >> a[i] >> b[i] >> c[i];

        dpa.assign(N, 0);
        dpb.assign(N, 0);
        dpc.assign(N, 0);
    }

    void solve() {
        rep(i, N) {
            if (i == 0) {
                dpa[i] = a[i];
                dpb[i] = b[i];
                dpc[i] = c[i];
            } else {
                dpa[i] = a[i] + max(dpb[i-1], dpc[i-1]);
                dpb[i] = b[i] + max(dpa[i-1], dpc[i-1]);
                dpc[i] = c[i] + max(dpa[i-1], dpb[i-1]);
            }
        }

        cout << max(max(dpa[N - 1], dpb[N - 1]), dpc[N - 1]) << endl;
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
