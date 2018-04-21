#include <stdio.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int A, B, C, X, Y;
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

    int xy = (X < Y) ? X : Y;

    int c = ((2 * C) < (A + B)) ? 2 * C : (A + B);

    if (X < Y) {
        if (c > B) printf("%d\n", xy * c + (Y - xy) * B);
        else printf("%d\n", xy * c + (Y - xy) * c);
    } else {
        if (c > A) printf("%d\n", xy * c + (X - xy) * A);
        else printf("%d\n", xy * c + (X - xy) * c);
    }

    return 0;
}
