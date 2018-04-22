#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {

    int n;
    scanf("%d", &n);

    int a[n];
    REP(i, n) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);
    int m = a[n - 1];
    int r = m / 2;

    REP(i, n) {
        if (r < a[i]) {
            a[i] = m - a[i];
        }
    }

    sort(a, a + n);

    int rr = 0;
    REP(i, n) {
        if (a[i] < r + 1) {
            rr = (r <= a[i]) ? m - a[i] : a[i];
        } else {
            break;
        }
    }

    printf("%d %d\n", m, rr);

    return 0;
}
