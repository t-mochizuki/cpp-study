#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {

    int N;
    scanf("%d", &N);

    if (N <= 999) {
        printf("ABC\n");
    } else {
        printf("ABD\n");
    }

    return 0;
}
