#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define RREP(n, i) for (int i = n - 1; i > -1; --i)

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

    long ans = 0;

    long a = 0;
    long c = 0;
    REP(b, N) {
        while (A[a] < B[b] && a < N) {
            a++;
        }

        while (B[b] >= C[c] && c < N) {
            c++;
        }

        // printf("%d * (%d - %d) = %d\n", a, N, c, a * (N - c));
        ans += a * (N - c);
    }


    printf("%ld\n", ans);

    return 0;
}
