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

    long low = 0;
    long high = 1e9;
    long T = 0;
    long temp = 0;
    while (abs(high - low) > 1) {
        T = (low + high) / 2;

        temp = 0;
        REP(i, N) {
            long hi = h[i] - (B * T);
            if (hi > 0) {
                temp += hi / (A - B);
                temp += ((hi % (A - B)) == 0) ? 0 : 1;
            }
        }

        // printf("temp = %ld, T = %ld, high = %d, low = %d\n", temp, T, high, low);
        if (temp <= T) {
            high = T;
        } else {
            low = T;
        }
    }

    printf("%ld\n", high);

    return 0;
}
