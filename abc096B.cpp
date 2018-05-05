#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    int K;
    scanf("%d", &K);

    long D = max(A, max(B, C));
    long ans = A + B + C - D;
    D = D << K;
    ans += D;

    printf("%ld\n", ans);

    return 0;
}


