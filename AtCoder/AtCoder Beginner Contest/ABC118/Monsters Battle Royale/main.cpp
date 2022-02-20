#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int A[N];
    REP(0, i, N) {
        cin >> A[i];
    }

    sort(A, A + N);

    while (true) {
        bool done = true;

        REP(1, i, N) {
            if (A[i] % A[0] == 0) {
                A[i] = A[0];
            } else {
                A[i] %= A[0];
            }
        }

        REP(1, i, N) {
            if (A[i] != A[0]) {
                done = false;
                break;
            }
        }

        if (done) {
            break;
        }

        sort(A, A + N);
    }

    cout << A[0] << endl;

    return 0;
}
