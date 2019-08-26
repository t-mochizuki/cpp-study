#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, M;
    cin >> N >> M;

    int X[M];
    REP(0, i, M) {
        cin >> X[i];
    }

    sort(X, X + M);

    // REP(0, i, M) {
    //     if (i == 0) {
    //         printf("%d", X[i]);
    //     } else {
    //         printf(", %d", X[i]);
    //     }
    // }
    // printf("\n");

    int D[M - 1];
    REP(0, i, M - 1) {
        D[i] = X[i + 1] - X[i];
    }

    // REP(0, i, M - 1) {
    //     printf("%d\n", D[i]);
    // }

    sort(D, D + M - 1);

    int ans = 0;
    REP(0, i, M - N) {
        ans += D[i];
    }

    cout << ans << endl;

    return 0;
}
