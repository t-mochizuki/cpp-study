#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int max(int X, int Y) {
    return X > Y ? X : Y;
}

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int abs(int a, int b) {
    return max(b - a, a - b);
}

int main() {
    int xa, ya;
    int xb, yb;
    int xc, yc;
    scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);

    // 三角形の頂点の１つが原点にあるとき、
    // 三角形の面積は|ad - bc| / 2
    printf("%.1lf\n", (abs((xb - xa) * (yc - ya), (yb - ya) * (xc - xa)) / 2.0));

    return 0;
}
