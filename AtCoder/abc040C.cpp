#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

const int INDEFINITE = -1;

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int abs(int X) {
    return X > 0 ? X : -X;
}

int dp(int N, int a[], int m[]) {
    if (m[N] != INDEFINITE) {
        return m[N];
    }

    if (2 == N) {
        m[N] = abs(a[N] - a[N - 1]);
    } else if (3 == N) {
        int before1 = dp(N - 1, a, m);
        m[N] = min(abs(a[N] - a[N - 2]), abs(a[N] - a[N - 1]) + before1);
    } else {
        int before1 = dp(N - 1, a, m);
        int before2 = dp(N - 2, a, m);
        m[N] = min(abs(a[N] - a[N - 2]) + before2, abs(a[N] - a[N - 1]) + before1);
    }

    return m[N];
}

int main() {
    int N; cin >> N; // 2 <= N <= 10^5
    int a[N + 1]; // 0 <= a[i] < 10^4
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    int m[N + 1];
    for (int i = 1; i <= N; ++i) {
        m[i] = INDEFINITE;
    }

    cout << dp(N, a, m) << endl;

    return 0;
}
