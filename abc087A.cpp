#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int X, A, B;
    scanf("%d %d %d", &X, &A, &B);

    printf("%d\n", (X - A) % B);

    return 0;
}
