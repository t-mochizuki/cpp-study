#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    // N * (N + 1) / 2
    // 10000 * ((N * (N + 1) / 2.0) / N) = 5000 * (N + 1)
    printf("%d\n", 5000 * (N + 1));

    return 0;
}
