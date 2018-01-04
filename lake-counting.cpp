#include <iostream>

using namespace std;

int n, m;
const int MAX_N = 100;
const int MAX_M = 100;
char field[MAX_N][MAX_M + 1];


void dfs(int x, int y) {

    field[x][y] = '.';

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx;
            int my = y + dy;

            if (0 <= nx && nx < n && 0 <= my && my < m && field[nx][my] == 'W') {
                dfs(nx, my);
            }
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%s", field[i]);
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j] == 'W') {
                dfs(i, j);
                ++count;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}

/*
Input:
3 4
W.W.
....
WWWW

Output:
3
*/
