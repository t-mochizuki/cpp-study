#include <stdio.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
    int T; scanf("%d", &T);

    for (int id = 1; id <= T; ++id) {
        int A; scanf("%d", &A);
        int column = 2;
        int row = 2;
        int I, J;
        bool matrix[1000][1000];
        REP(i, 1000) REP(j, 1000) {
            matrix[i][j] = false;
        }
        while (true) {
            printf("%d %d\n", row, column);
            fflush(stdout);

            scanf("%d %d", &I, &J);

            if (I == -1 && J == -1) {
                break; // Error
            }

            if (I == 0 && J == 0) {
                break;
            }

            matrix[I][J] = true;

            if (matrix[row - 1][column - 1]
                    && matrix[row - 1][column]
                    && matrix[row - 1][column + 1]
                    && matrix[row][column - 1]
                    && matrix[row][column]
                    && matrix[row][column + 1]
                    && matrix[row + 1][column - 1]
                    && matrix[row + 1][column]
                    && matrix[row + 1][column + 1]
                    ) {
                column += 3;
            }
        }

        if (I == -1 && J == -1) {
            break; // Error
        }
    }

    return 0;
}
