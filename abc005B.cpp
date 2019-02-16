#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int main() {
    int N;
    scanf("%d", &N);

    int ans = 100;
    REP(0, i, N) {
        int T;
        scanf("%d", &T);
        ans = min(ans, T);
    }

    printf("%d\n", ans);

    return 0;
}
