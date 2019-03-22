#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    long N, K;
    cin >> N >> K;

    long s[N];
    REP(0, i, N) {
        cin >> s[i];
    }

    REP(0, i, N) {
        if (s[i] == 0) {
            printf("%ld\n", N);
            return 0;
        }
    }

    int lhs = 0;
    int rhs = 0;
    int ans = 0;
    long acc = 1;
    while (lhs < N) {
        if (acc > K) {
            // K = 0 のときに rhs == lhs を満たす。
            if (rhs == lhs) {
                rhs++;
            } else {
                acc /= s[lhs];
            }
            lhs++;
        } else {
            if (rhs - lhs > ans) {
                ans = rhs - lhs;
            }

            if (rhs < N) {
                acc *= s[rhs];
                rhs++;
            } else {
                lhs++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
