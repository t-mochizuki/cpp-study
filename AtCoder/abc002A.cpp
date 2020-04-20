#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int max(int X, int Y) {
    return X > Y ? X : Y;
}

int main() {
    int X, Y;
    scanf("%d %d", &X, &Y);

    printf("%d\n", max(X, Y));

    return 0;
}
