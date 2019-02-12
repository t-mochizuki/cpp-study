#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int R[N];
    REP(0, i, N) {
        scanf("%d", &R[i]);
    }

    sort(R, R + N);

    // K + (N - K) = N
    double ans = 0;
    REP(N - K, i, N) {
        ans = (ans + R[i]) / 2;
    }

    printf("%lf\n", ans);

    return 0;
}
