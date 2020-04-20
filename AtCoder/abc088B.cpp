#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    int a[N];
    REP(0, i, N) {
        scanf("%d", &a[i]);
    }

    sort(a, a + N, greater<int>());

    // REP(0, i, N) {
    //     printf("%d\n", a[i]);
    // }

    int ans = 0;
    REP(0, i, N) {
        if (i % 2 == 0) {
            ans += a[i];
        } else {
            ans -= a[i];
        }
    }

    printf("%d\n", ans);

    return 0;
}
