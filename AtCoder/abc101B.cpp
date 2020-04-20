#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {

    int N = 0;
    scanf("%d", &N);

    int tmp = N;

    int S = 0;
    while (tmp) {
        S += tmp % 10;
        tmp /= 10;
    }

    if (N % S == 0) printf("Yes\n");
    else printf("No\n");

    return 0;
}
