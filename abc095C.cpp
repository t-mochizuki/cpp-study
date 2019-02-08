#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int max(int X, int Y) {
    return X > Y ? X : Y;
}

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int main() {

    int A, B, C, X, Y;
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

    int ans = 0;
    if (A + B <= 2 * C) {
        ans = A * X + B * Y;
    } else {
        // 2 * C < A + B
        if (2 * C <= A && 2 * C <= B) {
            ans = 2 * C * max(X, Y);
        } else if (2 * C <= A) {
            if (Y > X) {
                ans = 2 * C * X + B * (Y - X);
            } else {
                ans = 2 * C * X;
            }
        } else if (2 * C <= B) {
            if (Y > X) {
                ans = 2 * C * Y;
            } else {
                ans = 2 * C * Y + A * (X - Y);
            }
        } else {
            if (Y > X) {
                ans = 2 * C * X + B * (Y - X);
            } else {
                ans = 2 * C * Y + A * (X - Y);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
