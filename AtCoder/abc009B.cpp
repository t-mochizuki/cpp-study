#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    REP(0, i, N) {
        scanf("%d", &A[i]);
    }

    sort(A, A + N, greater<int>());

    REP(0, i, N) {
        if (A[i] < A[0]) {
            printf("%d\n", A[i]);
            break;
        }
    }

    return 0;
}
