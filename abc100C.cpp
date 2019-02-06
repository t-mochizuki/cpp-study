#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {

    int N;
    scanf("%d", &N);

    long a[N];
    REP(0, i, N) {
        scanf("%ld", &a[i]);
    }

    int cnt = 0;
    int idx = 0;
    while (true) {
        if (a[idx] % 2 == 0) {
            cnt++;
            a[idx] /= 2;
        } else {
            idx++;
        }

        if (idx == N) {
            break;
        }
    }

    printf("%d\n", cnt);

    return 0;
}
