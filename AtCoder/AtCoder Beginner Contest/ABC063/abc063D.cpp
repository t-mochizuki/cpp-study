#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);

    int h[N];
    REP(i, N) {
        scanf("%d", &h[i]);
    }

    sort(h, h + N, greater<int>());

    long ng = 0;
    long ok = 1e9;
    while (abs(ok - ng) > 1) {
        long mid = (ng + ok) / 2;

        long count = 0;
        REP(i, N) {
            long hi = h[i] - (B * mid);
            if (hi > 0) {
                count += (hi + (A - B) - 1) / (A - B);
            }
        }

        // printf("count = %ld, mid = %ld, ok = %d, ng = %d\n", count, mid, ok, ng);
        if (count <= mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    printf("%ld\n", ok);

    return 0;
}
