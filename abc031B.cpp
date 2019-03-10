#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int L, H;
    cin >> L >> H;

    int N;
    cin >> N;

    int A[N];
    REP(0, i, N) {
        cin >> A[i];
    }

    REP(0, i, N) {
        if (A[i] < L) {
            printf("%d\n", L - A[i]);
            continue;
        } else if (H < A[i]) {
            printf("%d\n", -1);
            continue;
        } else {
            printf("%d\n", 0);
        }
    }

    return 0;
}
