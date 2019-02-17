#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int dp(int idx, int* a) {
    if (a[idx] != -1) {
        return a[idx];
    }

    a[idx - 3] = dp(idx - 3, a);
    a[idx - 2] = dp(idx - 2, a);
    a[idx - 1] = dp(idx - 1, a);

    return (a[idx - 1] + a[idx - 2] + a[idx - 3]) % 10007;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[1000000];
    REP(0, i, 1000000) {
        a[i] = -1;
    }

    a[0] = 0;
    a[1] = 0;
    a[2] = 1;

    int ans = dp(n - 1, a);

    printf("%d\n", ans);

    return 0;
}
