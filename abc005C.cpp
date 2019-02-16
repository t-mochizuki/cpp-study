#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int T;
    scanf("%d", &T);

    int N;
    scanf("%d", &N);

    int A[N];
    REP(0, i, N) {
        scanf("%d", &A[i]);
    }

    int M;
    scanf("%d", &M);

    int B[M];
    REP(0, i, M) {
        scanf("%d", &B[i]);
    }

    int j = 0;
    REP(0, i, N) {
        if (A[i] <= B[j] && B[j] <= A[i] + T) {
            j++;
        }

        if (j >= M) {
            printf("yes\n");
            return 0;
        }
    }

    printf("no\n");

    return 0;
}
