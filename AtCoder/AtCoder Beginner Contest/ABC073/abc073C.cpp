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

    int cnt = 0;
    REP(i, N) {
        if (A[i] == A[i + 1]) {
            i++;
        } else {
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}
