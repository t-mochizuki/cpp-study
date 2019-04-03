#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, Q;
    cin >> N >> Q;

    int L[N];
    REP(0, i, N) {
        L[i] = 0;
    }

    int l, r;
    REP(0, j, Q) {
        cin >> l >> r;
        l--; // zero origin

        REP(l, j, r) {
            if (L[j] == 0) {
                L[j] = 1;
            } else {
                L[j] = 0;
            }
        }
    }

    REP(0, i, N) {
        cout << L[i];
    }
    cout << endl;

    return 0;
}
