#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, M;
    cin >> N >> M;

    int A[N + 1];
    REP(0, i, N + 1) A[i] = 0;

    REP(0, j, M) {
        int L, R;
        cin >> L >> R;
        L--;

        A[L]++; A[R]--;
    }

    // REP(0, i, N + 1) cout << A[i] << endl;

    int B[N];
    REP(0, i, N) {
        if (i == 0) B[0] = A[0];
        else B[i] = B[i - 1] + A[i];
    }

    int ans = 0;
    REP(0, i, N) {
        if (B[i] == M) ans++;
    }

    cout << ans << endl;

    return 0;
}
