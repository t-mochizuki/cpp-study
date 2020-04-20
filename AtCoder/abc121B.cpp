#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, M, C;
    cin >> N >> M >> C;

    int B[M];
    REP(0, i, M) {
        cin >> B[i];
    }

    int A[N][M];
    REP(0, i, N) {
        REP(0, j, M) {
            cin >> A[i][j];
        }
    }

    int cnt = 0;
    REP(0, i, N) {
        int acc = 0;

        REP(0, j, M) {
            acc += A[i][j] * B[j];
        }

        acc += C;

        if (acc > 0) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
