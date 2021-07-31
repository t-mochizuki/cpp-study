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

    int dp(int N, int K, int h[], int m[]) {
        int idx = N - 1;

        if ((-1) != m[idx]) {
            return m[idx];
        }

        if (2 == N) {
            return abs(h[idx], h[idx - 1]);
        } else {
            for (int i = 1; i < K + 1; ++i) {
                if (N - i >= 2) {
                    m[idx - i] = dp(N - i, K, h, m);
                }
            }

            int ans = 2000000000;
            for (int i = 1; i < K + 1; ++i) {
                if (N - i >= 2) {
                    ans = min(ans, abs(h[idx], h[idx - i]) + m[idx - i]);
                } else {
                    ans = min(ans, abs(h[idx], h[idx - i]));
                    break;
                }
            }

            return ans;
        }
    }

    void solve() {
        int N; // 2 <= N <= 10^5
        int K; // 1 <= K <= 100
        cin >> N >> K;

        int h[N]; // 1 <= hi <= 10^4
        rep(i, N) {
            cin >> h[i];
        }

        int m[N];
        rep(i, N) {
            m[i] = -1;
        }

        printf("%d\n", dp(N, K, h, m));
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
