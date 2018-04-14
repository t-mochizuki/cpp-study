#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {

    int N;
    scanf("%d", &N);

    int X[N], temp[N];
    REP(i, N) {
        scanf("%d", &X[i]);
        temp[i] = X[i];
    }

    sort(X, X + N);

    int l = X[N / 2 - 1];
    int r = X[N / 2];
    REP(i, N) {
        if (temp[i] <= l) {
            printf("%d\n", r);
        } else {
            printf("%d\n", l);
        }
    }

    return 0;
}
