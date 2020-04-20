#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int main() {
    int N, M, X;
    scanf("%d %d %d", &N, &M, &X);

    int A, cnt = 0;
    REP(0, i, M) {
        scanf("%d", &A);
        if (A < X) cnt++;
    }

    printf("%d\n", min(cnt, M - cnt));

    return 0;
}
