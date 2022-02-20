#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int abs(int X, int Y) {
    return X > Y ? X - Y : Y - X;
}

int median(int* A, int n) {
    if (n % 2 == 1) {
        return A[(n + 1) / 2 - 1];
    } else {
        return (A[n / 2 - 1] + A[n / 2]) / 2;
    }
}

int main() {
    int N;
    cin >> N;

    int A[N];
    REP(0, i, N) {
        cin >> A[i];
    }

    int B[N];
    REP(0, i, N) {
        B[i] = A[i] - i;
    }

    sort(B, B + N);
    int b = median(B, N);

    long ans = 0;
    REP(0, i, N) {
        ans += abs(B[i] - b);
    }

    printf("%ld\n", ans);

    return 0;
}
