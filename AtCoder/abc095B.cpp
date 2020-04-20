#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    int m[N];
    int mi = 1000;
    REP(0, i, N) {
        scanf("%d", &m[i]);
        X -= m[i];
        if (m[i] < mi) {
            mi = m[i];
        }
    }

    int ans = N;
    while (true) {
        if (mi <= X) {
            X -= mi;
            ans++;
        } else {
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}
