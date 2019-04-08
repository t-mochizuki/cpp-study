#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, Q;
    cin >> N >> Q;

    int a[N];
    REP(0, i, N) {
        a[i] = 0;
    }

    REP(0, i, Q) {
        int L, R, T;
        cin >> L >> R >> T;

        L--; // zero origin

        REP(L, j, R) {
            a[j] = T;
        }
    }

    REP(0, i, N) {
        cout << a[i] << endl;
    }

    return 0;
}
