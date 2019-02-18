#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int abs(int X, int Y) {
    return X > Y ? X - Y : Y - X;
}

int main() {
    int N;
    cin >> N;

    int A[N];
    REP(0, i, N) {
        cin >> A[i];
    }

    sort(A, A + N);

    printf("%d\n", abs(A[0], A[N - 1]));

    return 0;
}
