#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A[3];
    REP(0, i, 3) {
        cin >> A[i];
    }

    sort(A, A + 3);

    cout << A[2] - A[0] << endl;

    return 0;
}
