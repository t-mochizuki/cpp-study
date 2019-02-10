#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    printf("%d\n", min(A, B) + min(C, D));

    return 0;
}
