#include <stdio.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int abs(int l, int r) { return (l > r) ? l - r : r - l; }
int max(int l, int r) { return (l > r) ? l : r; }

int main() {
    int N, Z, W;
    scanf("%d %d %d", &N, &Z, &W);

    int a[N];
    REP(i, N) {
        scanf("%d", &a[i]);
    }

    if (N == 1) {
        printf("%d\n", abs(W, a[N - 1]));
    } else {
        printf("%d\n", max(abs(W, a[N - 1]), abs(a[N - 2], a[N - 1])));
    }

    return 0;
}
