#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int n;
    scanf("%d", &n);

    int petals[9] = {0, 1, 0, 1, 2, 3, 0, 1, 0};
    int ans = 0;
    int a;
    REP(0, i, n) {
        scanf("%d", &a);
        ans += petals[a - 1];
    }

    printf("%d\n", ans);

    return 0;
}
