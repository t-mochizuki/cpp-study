#include <stdio.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int H, W;
    scanf("%d %d", &H, &W);

    // 1 つの数字を i から j に書き変えるには魔力 cij が必要
    int c[10][10];
    REP(i, 10) {
        REP(j, 10) {
            scanf("%d", &c[i][j]);
        }
    }

    REP(k, 10) {
        REP(i, 10) {
            REP(j, 10) {
                if (c[i][j] > c[i][k] + c[k][j]) {
                    c[i][j] = c[i][k] + c[k][j];
                }
            }
        }
    }

    int ans = 0;
    REP(i, H) {
        REP(j, W) {
            int aij = 0;
            scanf("%d", &aij);

            if (aij == -1) continue;

            ans += c[aij][1];
        }
    }

    printf("%d\n", ans);

    return 0;
}
