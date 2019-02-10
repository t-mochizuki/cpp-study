#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, A;
    scanf("%d %d", &N, &A);

    N = N % 500;

    if (N > A) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}
