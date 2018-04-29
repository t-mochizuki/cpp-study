#include <stdio.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int H, W;
const int MAX_W = 501;
const int MAX_H = 500;
char town[MAX_W][MAX_H];
bool reached[MAX_W][MAX_H];

void deepFirstSearch(int column, int row) {
    if (column < 0 || W <= column ||
        row < 0 || H <= row ||
        town[row][column] == '#') return;

    if (reached[row][column] == true) return;

    reached[row][column] = true;

    deepFirstSearch(column + 1, row);
    deepFirstSearch(column - 1, row);
    deepFirstSearch(column, row + 1);
    deepFirstSearch(column, row - 1);
}

int main() {
    scanf("%d %d", &H, &W);

    REP(row, H) {
        scanf("%s", town[row]);
    }

    int s_column, s_row, g_column, g_row;
    REP(row, H) {
        REP(column, W) {
            reached[row][column] = false;

            if (town[row][column] == 's') {
                s_column = column;
                s_row = row;
            }
            if (town[row][column] == 'g') {
                g_column = column;
                g_row = row;
            }
        }
    }

    // REP(row, H) {
    //     REP(column, W) {
    //         printf("reached[%d][%d] = %d\n", row, column, reached[row][column]);
    //     }
    // }

    deepFirstSearch(s_column, s_row);

    // REP(row, H) {
    //     REP(column, W) {
    //         printf("reached[%d][%d] = %d\n", row, column, reached[row][column]);
    //     }
    // }

    if (reached[g_row][g_column]) printf("Yes\n");
    else printf("No\n");

    return 0;
}
