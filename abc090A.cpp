#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    char c1[4];
    scanf("%s", c1);

    char c2[4];
    scanf("%s", c2);

    char c3[4];
    scanf("%s", c3);

    printf("%c%c%c\n", c1[0], c2[1], c3[2]);

    return 0;
}
