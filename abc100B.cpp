#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {

    int D, N;
    scanf("%d %d", &D, &N);

    int a = 0;
    if (D == 0) {
        a = 1;
    } else if (D == 1) {
        a = 100;
    } else {
        a = 10000;
    }

    printf("%d\n", N == 100 ? a * 101 : a * N);

    return 0;
}
