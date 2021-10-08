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

    int N;
    vector<int> a, b;

public:
    Problem() {
        cin >> N;

        a.resize(N);
        rep(i, 0, N) cin >> a[i];
        sort(a.begin(), a.end());

        b.resize(N);
        rep(i, 0, N) cin >> b[i];
        sort(b.begin(), b.end());
    }

    void solve() {
        long y = 0;
        rep(i, 0, N) y += abs(a[i] - b[i]);
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
