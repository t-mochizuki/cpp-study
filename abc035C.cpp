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

        L[l]++;
        L[r]--;
    }

    REP(1, i, N) {
        L[i] += L[i - 1];
    }

    REP(0, i, N) {
        L[i] %= 2;
    }

    REP(0, i, N) {
        cout << L[i];
    }
    cout << endl;

    return 0;
}
