#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class Problem {
private:

public:
    Problem() {
    }

    int max(int X, int Y) {
        return X > Y ? X : Y;
    }

    int min(int X, int Y) {
        return X < Y ? X : Y;
    }

    int abs(int X, int Y) {
        return X > Y ? X - Y : Y - X;
    }

    int dp(int N, int h[], int m[]) {
        int idx = N - 1;

        if ((-1) != m[idx]) {
            return m[idx];
        }

        if (2 == N) {
            return abs(h[idx], h[idx - 1]);
        } else if (3 == N) {
            m[idx - 1] = dp(N - 1, h, m);
            return min(abs(h[idx], h[idx - 2]), abs(h[idx], h[idx - 1]) + m[idx - 1]);
        } else {
            m[idx - 2] = dp(N - 2, h, m);
            m[idx - 1] = dp(N - 1, h, m);
            return min(abs(h[idx], h[idx - 2]) + m[idx - 2], abs(h[idx], h[idx - 1]) + m[idx - 1]);
        }
    }

    void solve() {
        int N; // 2 <= N <= 10^5
        cin >> N;

        int h[N]; // 1 <= hi <= 10^4
        rep(i, N) {
            cin >> h[i];
        }

        int m[N];
        rep(i, N) {
            m[i] = -1;
        }

        printf("%d\n", dp(N, h, m));
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
