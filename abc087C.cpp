#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int max(int X, int Y) {
    return X > Y ? X : Y;
}

int main() {
    int N;
    scanf("%d", &N);

    int A[2][N];
    REP(0, i, 2) REP(0, j, N) {
        scanf("%d", &A[i][j]);
    }

    int ans = 0;
    REP(0, k, N) {
        int temp = 0;
        REP(0, j, k + 1) {
            temp += A[0][j];
        }
        REP(k, j, N) {
            temp += A[1][j];
        }
        ans = max(temp, ans);
    }

    printf("%d\n", ans);

    return 0;
}
