#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, S, T;
    cin >> N >> S >> T;

    int A[N];
    REP(0, i, N) {
        cin >> A[i];
    }

    int cnt = 0;
    REP(0, i, N) {
        if (i != 0) {
            A[i] += A[i - 1];
        }

        if (S <= A[i] && A[i] <= T) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
