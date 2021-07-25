#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define RREP(n, i) for (int i = n - 1; i > -1; --i)

int N; // カウンター上には N 貫の寿司 10^5
long C; // カウンターの外周の長さ 10^14

// 消費したエネルギー
long energy(long a, long b) {
    long ab = a + b;
    return (a < b) ? ab + a : ab + b;
}

int main() {
    scanf("%d %ld", &N, &C);

    long x[N];
    long v[N];
    REP(i, N) {
        scanf("%ld %ld", &x[i], &v[i]);
    }

    long vs1[N];
    REP(i, N) {
        vs1[i] = (i == 0) ? v[0] : vs1[i - 1] + v[i];
    }

    // REP(i, N) {
    //     printf("%ld\n", vs1[i]);
    // }

    long vsN[N];
    RREP(N, i) {
        vsN[i] = (i == N - 1) ? v[N - 1] : vsN[i + 1] + v[i];
    }

    // RREP(N, i) {
    //     printf("%ld\n", vsN[i]);
    // }

    long ans = 0;

    // B = O
    REP(i, N) {
        long e = energy(x[i], 0);
        ans = max(vs1[i] - e, ans);
        // printf("ans = %ld\n", ans);
    }

    // A = O
    RREP(N, i) {
        long e = energy(0, C - x[i]);
        ans = max(vsN[i] - e, ans);
        // printf("ans = %ld\n", ans);
    }

    // A != O, B != O
    for (int a = 0; a < N; ++a) {
        // printf("N = %d, a = %d\n", N, a);
        for (int b = N - 1; b > 0; --b) {
            if (a >= b) break;

            long e = energy(x[a], C - x[b]);
            ans = max(vs1[a] + vsN[b] - e, ans);
            // printf("vs1[a] = %ld, vsN[b] = %ld, e = %ld, ans = %ld\n", vs1[a], vsN[b], e, ans);
        }
    }

    printf("%ld\n", ans);

    return 0;
}
