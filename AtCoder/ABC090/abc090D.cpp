#include <stdio.h>

using namespace std;

#define rep(a, i, n) for (int i = a; i <= n; ++i)

long max(long l, long r) {
    return l > r ? l : r;
}

int main() {
    // a, b は N 以下
    // a を b で割った余りが K 以上

    long N, K;
    scanf("%ld %ld", &N, &K);

    if (K == 0) {
        printf("%ld\n", N * N);
        return 0;
    }

    long ans = 0;
    rep(1, b, N) {
        long p = N / b;
        ans += p * max(0, b - K);
        long r = N % b;
        ans += max(0, r - K + 1);
    }

    printf("%ld\n", ans);

    return 0;
}
