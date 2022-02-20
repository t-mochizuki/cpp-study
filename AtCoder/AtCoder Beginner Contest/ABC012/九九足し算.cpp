#include <stdio.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    scanf("%d", &N);

    int table[9][9];
    REP(0, i, 9) {
        REP(0, j, 9) {
            table[i][j] = (i + 1) * (j + 1);
        }
    }

    int ans = 2025 - N;
    REP(0, i, 9) {
        REP(0, j, 9) {
            if (ans == table[i][j]) {
                printf("%d x %d\n", (i + 1), (j + 1));
            }
        }
    }

    return 0;
}
