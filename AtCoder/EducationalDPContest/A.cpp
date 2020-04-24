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

int main() {
    int N; // 2 <= N <= 10^5
    scanf("%d", &N);

    int h[N]; // 1 <= hi <= 10^4
    REP(0, i, N) {
        scanf("%d", &h[i]);
    }

    int m[N];
    REP(0, i, N) {
        m[i] = -1;
    }

    printf("%d\n", dp(N, h, m));

    return 0;
}
