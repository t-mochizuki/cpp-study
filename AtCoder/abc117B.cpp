#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int L[N];
    REP(0, i, N) {
        cin >> L[i];
    }

    sort(L, L + N);

    int acc = 0;
    REP(0, i, N) {
        acc += L[i];
    }

    if (acc > 2 * L[N - 1]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
