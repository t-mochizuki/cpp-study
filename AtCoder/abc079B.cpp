#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    long L[N];
    L[0] = 2;
    L[1] = 1;
    REP(2, i, N + 1) {
        L[i] = L[i - 1] + L[i - 2];
    }

    cout << L[N] << endl;

    return 0;
}
