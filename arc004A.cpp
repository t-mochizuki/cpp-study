#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int length(int dx, int dy) {
    return dx * dx + dy * dy;
}

int main() {
    int N;
    scanf("%d", &N);

    int x[N];
    int y[N];
    REP(i, N) {
        scanf("%d %d", &x[i], &y[i]);
    }

    int temp = 0;
    REP(a, N) {
        REP(b, N) {
            temp = max(length(x[b] - x[a], y[b] - y[a]), temp);
        }
    }

    printf("%lf\n", sqrt(1.0 * temp));
    return 0;
}
