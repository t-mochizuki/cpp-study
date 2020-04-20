#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {

    int a, b;
    scanf("%d %d", &a, &b);

    int n = b - a;
    int c = n * (1 + n) / 2;

    printf("%d\n", c - b);

    return 0;
}
