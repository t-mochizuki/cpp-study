#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

struct data_t {
    int r;
    int c;
};

int main() {
    int R, C, K;
    cin >> R >> C >> K;

    int N;
    cin >> N;

    int M[R][C];
    REP(0, i, R) {
        REP(0, j, C) {
            M[i][j] = 0;
        }
    }

    int r, c;
    data_t A[N];
    REP(0, i, N) {
        cin >> r >> c;
        A[i] = (data_t){r - 1, c - 1};
        M[r - 1][c - 1] = 1;
    }

    int rx[R];
    REP(0, i, R) {
        rx[i] = 0;
    }

    REP(0, i, N) {
        rx[A[i].r]++;
    }

    int cx[C];
    REP(0, i, C) {
        cx[i] = 0;
    }

    REP(0, i, N) {
        cx[A[i].c]++;
    }

    long cnt = 0;
    REP(0, i, R) {
        REP(0, j, C) {
            if (rx[i] + cx[j] - M[i][j] == K) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
