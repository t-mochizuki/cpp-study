#include <stdio.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    long X = 100 * (N - M) + 1900 * M;
    X = X << M;

    printf("%ld\n", X);

    return 0;
}
