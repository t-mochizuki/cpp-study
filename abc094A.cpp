#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, B, X;
    scanf("%d %d %d", &A, &B, &X);

    if (A + B < X) {
        printf("NO\n");
    } else if (A > X) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }

    return 0;
}
