#include <stdio.h>
#include <cmath>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

struct coordinate_t {
    int x;
    int y;
};

double distance(coordinate_t a, coordinate_t b) {
    return sqrt(1.0 * (b.x - a.x) * (b.x - a.x) + 1.0 * (b.y - a.y) * (b.y - a.y));
}

int main() {
    int tx, ty, T, V;
    scanf("%d %d", &tx, &ty);
    coordinate_t a = (coordinate_t){tx, ty};

    scanf("%d %d", &tx, &ty);
    coordinate_t b = (coordinate_t){tx, ty};

    scanf("%d %d", &T, &V);
    int d = T * V;
    // printf("d=%d\n", d);

    int n;
    scanf("%d", &n);

    coordinate_t c[n];
    REP(0, i, n) {
        int x, y;
        scanf("%d %d", &x, &y);
        c[i] = (coordinate_t){x, y};
    }

    REP(0, i, n) {
        double d1 = distance(a, c[i]);
        // printf("d1=%f\n", d1);
        double d2 = distance(c[i], b);
        // printf("d2=%f\n", d2);

        if (d >= d1 + d2) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");

    return 0;
}
