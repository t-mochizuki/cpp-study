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

    int OB[N];
    int a = N - 1;
    RREP(N, i) {
        OB[i] = 0;
        while (B[i] <= A[a] && a > -1) {
            a--;
        }
        OB[i] = a + 1;
    }

    int OC[N];
    int b = N - 1;
    RREP(N, i) {
        OC[i] = 0;
        while (C[i] <= B[b] && b > -1) {
            b--;
        }
        OC[i] = b + 1;
    }

    long acc[N];
    int ob = 0;
    REP(i, N) {
        acc[i] = 0;

        if (OC[i] == 0) continue;

        if (i != 0) acc[i] = acc[i - 1];

        while (ob < OC[i]) {
            acc[i] += OB[ob];
            ob++;
        }
    }

    long ans = 0;
    REP(i, N) {
        ans += acc[i];
    }

    printf("%ld\n", ans);

    return 0;
}
