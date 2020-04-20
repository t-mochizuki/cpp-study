#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {

    int N, K;
    scanf("%d %d", &N, &K);

    int A[N];
    REP(0, i, N) {
        scanf("%d", &A[i]);
    }

    int cnt = 0;
    int idx = 0;
    while (true) {
        if (idx >= N - 1) {
            break;
        }
        cnt++;
        idx += K - 1;
    }

    printf("%d\n", cnt);
    return 0;
}
