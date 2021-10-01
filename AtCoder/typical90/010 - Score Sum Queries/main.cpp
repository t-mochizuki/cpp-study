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

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Problem {
private:

    int N;
    vector<int> p1, p2;
public:
    Problem() {
        cin >> N;

        p1.assign(N, 0);
        p2.assign(N, 0);
        rep(i, 0, N) {
            int C, P; cin >> C >> P;
            if (i == 0) {
                if (C == 1) {
                    p1[i] = P;
                } else {
                    p2[i] = P;
                }
            } else {
                p1[i] = (C == 1 ? P : 0) + p1[i-1];
                p2[i] = (C == 2 ? P : 0) + p2[i-1];
            }
        }
    }

    void debug() {
        rep(i, 0, N) {
            if (i == 0) cout << p1[i];
            else cout << "," << p1[i];
        }
        cout << endl;

        rep(i, 0, N) {
            if (i == 0) cout << p2[i];
            else cout << "," << p2[i];
        }
        cout << endl;
    }

    void solve() {
        // debug();

        int Q; cin >> Q;
        rep(i, 0, Q) {
            int L, R; cin >> L >> R;
            L--; R--;
            cout << p1[R]-(L-1 < 0 ? 0 : p1[L-1]) << " " << p2[R]-(L-1 < 0 ? 0 : p2[L-1]) << endl;
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
