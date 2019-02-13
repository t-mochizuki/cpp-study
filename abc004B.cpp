#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)
#define RREP(a, i, n) for (int i = n - 1; i >= 0; --i)

int main() {
    char c[4][4];
    REP(0, i, 4) {
        REP(0, j, 4) {
            cin >> c[i][j];
        }
    }

    // RREP(0, i, 4) {
    //     RREP(0, j, 4) {
    //         printf("c[%d][%d]=%c\n", i, j, c[i][j]);
    //     }
    // }

    RREP(0, i, 4) {
        RREP(0, j, 4) {
            if (j == 3) printf("%c", c[i][j]);
            else printf(" %c", c[i][j]);
        }
        printf("\n");
    }


    return 0;
}
