#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define RREP(n, i) for (int i = n - 1; i > -1; --i)

int main() {
    int N; // カウンター上には N 貫の寿司 10^5
    long C; // カウンターの外周の長さ 10^14
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

    REP(i, N) {
        printf("%ld\n", vs1[i]);
    }

    long vsN[N];
    RREP(N, i) {
        vsN[i] = (i == N - 1) ? v[N - 1] : vsN[i + 1] + v[i];
    }

    RREP(N, i) {
        printf("%ld\n", vsN[i]);
    }

    return 0;
}
