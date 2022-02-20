#include <stdio.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    int t = 0;
    int x = 0;
    int y = 0;
    REP(i, N) {
        int tt = t;
        int xx = x;
        int yy = y;

        scanf("%d %d %d", &t, &x, &y);

        int dt = t - tt;
        int dx = x - xx;
        int dy = y - yy;

        if (dx + dy > dt) {
            printf("No\n");
            return 0;
        }

        if ((dt - dx - dy) % 2 != 0) {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    return 0;
}
