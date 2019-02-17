#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int N, A, B; // 20, 100, 2000
    scanf("%d %d %d", &N, &A, &B);

    printf("%d\n", min(B, N * A));

    return 0;
}
