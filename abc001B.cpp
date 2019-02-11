#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int m;
    scanf("%d", &m);

    if (m < 100) {
        printf("00\n");
        return 0;
    }

    if (m <= 5000) {
        printf("%02d\n", m / 100);
        return 0;
    }

    if (6000 <= m && m <= 30000) {
        printf("%02d\n", m / 1000 + 50);
        return 0;
    }

    if (35000 <= m && m <= 70000) {
        printf("%02d\n", (m / 1000 - 30) / 5 + 80);
        return 0;
    }

    printf("89\n");

    return 0;
}
