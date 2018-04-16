#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    REP(i, N) {
        scanf("%d", &A[i]);
    }
    sort(A, A + N);

    int B[N];
    REP(i, N) {
        scanf("%d", &B[i]);
    }
    sort(B, B + N);

    int C[N];
    REP(i, N) {
        scanf("%d", &C[i]);
    }
    sort(C, C + N);

    int ans = 0;
    int i = N - 1;
    int j = N - 1;
    for (int k = N - 1; k > -1; --k) {
        while (C[k] <= B[j]) {
            --j;
        }
        if (j == -1) break;

        while (B[j] <= A[i]) {
            --i;
        }
        if (i == -1) break;

        int a = i;
        int b = j;
        while (b > -1) {
            while (B[b] <= A[a]) {
                --a;
            }
            ans += a + 1;
            --b;
        }
    }

    printf("%d\n", ans);

    return 0;
}
