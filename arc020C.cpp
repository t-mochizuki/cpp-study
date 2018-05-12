#include <stdio.h>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    char a[N][11];
    int L[N];
    REP(i, N) {
        scanf("%s %d", a[i], &L[i]);
    }

    int B;
    scanf("%d", &B);

    long ans = 0;
    REP(i, N) REP(j, L[i]) REP(k, strlen(a[i])) {
        // printf("%c\n", a[i][k]);
        ans = ((ans * 10) + (a[i][k] - '0')) % B;
    }

    printf("%ld\n", ans);

    return 0;
}
