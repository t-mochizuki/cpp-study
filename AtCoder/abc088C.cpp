#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int c[3][3];
    scanf("%d %d %d", &c[0][0], &c[0][1], &c[0][2]);
    scanf("%d %d %d", &c[1][0], &c[1][1], &c[1][2]);
    scanf("%d %d %d", &c[2][0], &c[2][1], &c[2][2]);

    int a12[3], a13[3], a23[3];
    REP(0, i, 3) {
        a12[i] = c[0][i] - c[1][i];
        a13[i] = c[0][i] - c[2][i];
        a23[i] = c[1][i] - c[2][i];
    }

    int b12[3], b13[3], b23[3];
    REP(0, i, 3) {
        b12[i] = c[i][0] - c[i][1];
        b13[i] = c[i][0] - c[i][2];
        b23[i] = c[i][1] - c[i][2];
    }

    // REP(0, i, 3) {
    //     printf("a12[%d]: %d\n", i, a12[i]);
    //     printf("a13[%d]: %d\n", i, a13[i]);
    //     printf("a23[%d]: %d\n", i, a23[i]);
    //     printf("b12[%d]: %d\n", i, b12[i]);
    //     printf("b13[%d]: %d\n", i, b13[i]);
    //     printf("b23[%d]: %d\n", i, b23[i]);
    // }

    if (a12[0] == a12[1] && a12[1] == a12[2] &&
        a13[0] == a13[1] && a13[1] == a13[2] &&
        a23[0] == a23[1] && a23[1] == a23[2] &&
        b12[0] == b12[1] && b12[1] == b12[2] &&
        b13[0] == b13[1] && b13[1] == b13[2] &&
        b23[0] == b23[1] && b23[1] == b23[2]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
