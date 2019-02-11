#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, B, C, X;
    scanf("%d %d %d %d", &A, &B, &C, &X);

    int ans = 0;
    REP(0, i, A + 1) REP(0, j, B + 1) REP(0, k, C + 1) {
        if (500 * i + 100 * j + 50 * k == X) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
