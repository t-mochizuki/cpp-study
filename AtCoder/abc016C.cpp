#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, M;
    cin >> N >> M;

    int X[N + 1][N + 1]; // 1 origin
    REP(0, i, N + 1) {
        REP(0, j, N + 1) {
            X[i][j] = 0;
        }
    }

    int A, B;
    REP(0, i, M) {
        cin >> A >> B;
        X[A][B] = 1;
        X[B][A] = 1;
    }

    REP(1, i, N + 1) {
        int cnt = 0;

        REP(1, j, N + 1) {
            if (i == j) {
                continue;
            }

            REP(1, k, N + 1) {
                if (i == k || k == j) {
                    continue;
                }

                if (X[i][j] == 1) {
                    break;
                }

                if (X[i][k] == 1 && X[k][j] == 1) {
                    cnt++;
                    break;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
