#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int max(int X, int Y) {
    return X > Y ? X : Y;
}

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    int m = max(A, max(B, C));

    int ax = m - A;
    int bx = m - B;
    int cx = m - C;
    int x = ax + bx + cx;

    if (x % 2 == 0) {
        printf("%d\n", x / 2);
    } else {
        printf("%d\n", (x + 3) / 2);
    }

    return 0;
}
