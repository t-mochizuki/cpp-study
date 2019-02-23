#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, T;
    cin >> N >> T;

    int A[N];
    REP(0, i, N) {
        cin >> A[i];
    }

    long cnt = 0;
    REP(1, i, N) {
        if (A[i - 1] + T < A[i]) {
            cnt += T;
        } else {
            cnt += A[i] - A[i - 1];
        }
    }

    cout << cnt + T << endl;

    return 0;
}
