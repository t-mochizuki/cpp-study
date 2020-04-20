#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {

    int A, B;
    scanf("%d %d", &A, &B);

    int C[3];
    C[0] = A + B;
    C[1] = A - B;
    C[2] = A * B;

    int ans = -1001;
    REP(0, i, 3) {
        if (ans < C[i]) ans = C[i];
    }

    printf("%d\n", ans);

    return 0;
}
