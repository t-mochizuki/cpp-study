#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

#define RREP(a, i, n) for (int i = n - 1; i >= 0; --i)

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
        REP(1, i, K + 1) {
            if (N - i >= 2) {
                m[idx - i] = dp(N - i, K, h, m);
            }
        }

        int ans = 2000000000;
        REP(1, i, K + 1) {
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

int main() {
    int N; // 2 <= N <= 10^5
    int K; // 1 <= K <= 100
    scanf("%d %d", &N, &K);

    int h[N]; // 1 <= hi <= 10^4
    REP(0, i, N) {
        scanf("%d", &h[i]);
    }

    int m[N];
    REP(0, i, N) {
        m[i] = -1;
    }

    printf("%d\n", dp(N, K, h, m));

    return 0;
}

/*
5 3
10 30 40 50 20
30

3 1
10 20 10
20

2 100
10 10
0

10 4
40 10 20 70 80 10 20 70 80 60
40
*/
