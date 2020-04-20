#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {

    int A, B;
    scanf("%d %d", &A, &B);

    REP(0, i, 16) {
        if (i % 2 == 0) {
            if (A != 0) {
                A--;
            }
        } else {
            if (B != 0) {
                B--;
            }
        }
    }

    if (A == 0 && B == 0) {
        printf("Yay!\n");
    } else {
        printf(":\(\n");
    }

    return 0;
}
