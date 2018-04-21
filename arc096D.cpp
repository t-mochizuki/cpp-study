#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define RREP(n, i) for (int i = n - 1; i > -1; --i)

int main() {
    int N;
    long C;
    scanf("%d %ld", &N, &C);

    long v = 0;
    long x = 0;
    long temp = 0;
    long xs[N];
    long vs[N];
    long c[N];
    long d[N];
    REP(i, N) {
        scanf("%ld %ld", &x, &v);
        xs[i] = x;
        vs[i] = v;
        c[i] = v - (x - temp);
        d[i] = (i == 0) ? c[0] : d[i - 1] + c[i];
        temp = x;
    }

    // REP(i, N) {
    //     printf("%ld %ld\n", c[i], d[i]);
    // }

    long* p = max_element(d, d + N);
    long ans = *p;
    int index = distance(d, p);
    if (ans > 0) {
        RREP(N, i) {
            if (index == i) break;

            if (vs[i] - 2 * (C - xs[i]) > 0) {
                ans += vs[i] - 2 * (C - xs[i]);
            } else {
                break;
            }
        }
        printf("%ld\n", ans);
    } else {
        printf("0\n");
    }


    return 0;
}
