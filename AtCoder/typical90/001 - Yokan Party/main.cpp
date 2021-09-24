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

// キーワード: 答えで二分探索

#define rep(i, a, n) for (int i = (a); i < (n); ++i)

class Problem {
private:

    int N, L, K;
    vector<int> a;

public:
    Problem() {
        cin >> N >> L >> K;

        a.resize(N+2);
        a[0] = 0;
        rep(i, 1, N+1) cin >> a[i];
        a[N+1] = L;
    }

    bool separable(int M) {
        int tmp = 0, piece = 0;
        rep(i, 1, N+2) {
            tmp += a[i] - a[i-1];

            if (tmp >= M) {
                tmp = 0;
                piece++;
            }
        }

        return piece >= K+1;
    }

    void solve() {
        int left = 0, right = L, pivot = 0;
        // 答えはM以上か
        while (right != left) {
            pivot = left + (right - left + 1) / 2;

            if (separable(pivot)) {
                left = pivot;
            } else {
                right = pivot - 1;
            }
        }
        cout << right << endl;
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
