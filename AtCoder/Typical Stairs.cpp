#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

const int INDEFINITE = -1;

int dp(int N, int m[]) {
    if (m[N] != INDEFINITE) {
        return m[N];
    }

    if (m[N] == 0) {
        return m[N];
    }

    if (1 == N) {
        m[N] = 1;
    } else if (2 == N) {
        int before1 = dp(N - 1, m);
        m[N] = before1 + 1;
    } else {
        int before1 = dp(N - 1, m);
        int before2 = dp(N - 2, m);
        if (before1 == 0 && before2 == 0) {
            m[N] = 0;
        } else if (before1 == 0) {
            m[N] = before2;
        } else if (before2 == 0) {
            m[N] = before1;
        } else {
            m[N] = (before1 + before2) % 1000000007;
        }
    }

    return m[N];
}

int main() {
    int N, M; cin >> N >> M; // 1 <= N <= 10^5
    int a[M + 1];
    for (int i = 1; i <= M; ++i) {
        cin >> a[i];
    }

    int m[N + 1];
    for (int i = 1; i <= N; ++i) {
        m[i] = INDEFINITE;
    }

    for (int i = 1; i <= M; ++i) {
        m[a[i]] = 0;
    }

    cout << dp(N, m) << endl;

    return 0;
}
