#include <stdio.h>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

const int INFTY = (1<<21);
int R, C;
int sy, sx;
int gy, gx;
const int MAX_R = 50;
const int MAX_C = 50;
char maze[MAX_R][MAX_C + 1];
int d[MAX_R][MAX_C];

void breadthFirstSearch() {
    pair<int, int> s = make_pair(sy, sx);
    queue<pair<int, int> > q;
    q.push(s);

    d[s.first][s.second] = 0;
    pair<int, int> u;

    while (! q.empty()) {
        u = q.front(); q.pop();
        int r = u.first;
        int c = u.second;
        // printf("r = %d, c = %d, maze[r + 1][c] = %c\n", r, c, maze[r + 1][c]);
        if (maze[r + 1][c] == '.' &&
            d[r + 1][c] == INFTY) {

            d[r + 1][c] = d[r][c] + 1;
            q.push(make_pair(r + 1, c));
        }
        if (maze[r - 1][c] == '.' &&
            d[r - 1][c] == INFTY) {

            d[r - 1][c] = d[r][c] + 1;
            q.push(make_pair(r - 1, c));
        }
        if (maze[r][c + 1] == '.' &&
            d[r][c + 1] == INFTY) {

            d[r][c + 1] = d[r][c] + 1;
            q.push(make_pair(r, c + 1));
        }
        if (maze[r][c - 1] == '.' &&
            d[r][c - 1] == INFTY) {

            d[r][c - 1] = d[r][c] + 1;
            q.push(make_pair(r, c - 1));
        }
    }
}

int main() {
    scanf("%d %d", &R, &C);
    scanf("%d %d", &sy, &sx);
    sy--; sx--;
    scanf("%d %d", &gy, &gx);
    gy--; gx--;

    REP(row, R) {
        scanf("%s", maze[row]);
    }

    REP(row, R) {
        REP(column, C) {
            d[row][column] = INFTY;
        }
    }

    breadthFirstSearch();

    // REP(y, R) {
    //     REP(x, C) {
    //         printf("d[%d][%d] = %d, ", y, x, d[y][x]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n", d[gy][gx]);

    return 0;
}
