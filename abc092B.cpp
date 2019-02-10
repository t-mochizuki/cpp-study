#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    int D, X;
    scanf("%d %d", &D, &X);

    int ans = 0;
    int A = 0;
    REP(0, i, N) {
        ans += 1;
        scanf("%d", &A);
        ans += (D - 1) / A;
    }

    ans += X;

    printf("%d\n", ans);

    return 0;
}
