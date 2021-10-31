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

    int N, K;
    vector<int> A, B;

public:

    Problem() {
        cin >> N >> K;

        A.resize(N);
        B.resize(N);
        rep(i, 0, N) {
            cin >> A[i];
        }
        rep(i, 0, N) {
            cin >> B[i];
        }
    }

    void solve() {
        rep(i, 0, N) {
            K -= abs(A[i]-B[i]);
        }

        if (K >= 0 && K % 2 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
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
