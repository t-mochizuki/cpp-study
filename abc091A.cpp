#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    if (A + B >= C) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
