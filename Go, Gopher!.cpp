#include <stdio.h>
#include <string.h>

int main() {
    int T; scanf("%d", &T);

    for (int id = 1; id <= T; ++id) {
        int A; scanf("%d", &A);
        int column = 2;
        int row = 2;
        bool f1, f2, f3 = false;
        int I, J;
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

            if (column - J == -1) {
                if (row == I) {
                    f2 = true;
                } else if (row - I == -1) {
                    f3 = true;
                } else if (row - I == 1) {
                    f1 = true;
                }
            }

            if (f1 && f2 && f3) {
                f1 = f2 = f3 = false;
                column++;
            }
        }

        if (I == -1 && J == -1) {
            break; // Error
        }
    }

    return 0;
}
