#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int calc(int i, int* R) {
    if (i == 0) return R[0] * R[0];
    else return R[i] * R[i] - calc(i - 1, R);
}

int main() {
    int N;
    cin >> N;

    int R[N];
    REP(0, i, N) {
        cin >> R[i];
    }

    sort(R, R + N);

    printf("%.7lf\n", calc(N - 1, R) * M_PI);

    return 0;
}
