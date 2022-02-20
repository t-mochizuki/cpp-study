#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

long gcd(long x, long y) {
    long r = x % y;
    while(r != 0) {
        x = y;
        y = r;
        r = x % y;
    }

    return y;
}

long lcm(long x, long y) {
    return (x * (y / gcd(x, y)));
}

int main() {
    int N; // 100
    scanf("%d", &N);

    long T[N]; // 1e18
    REP(0, i, N) {
        scanf("%ld", &T[i]);
    }
    sort(T, T + N);

    long ans = 0;
    REP(0, i, N) {
        ans = (i == 0) ? T[0] : lcm(ans, T[i]);
    }

    printf("%ld\n", ans);

    return 0;
}
