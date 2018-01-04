#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> P;

const int MAX = 100;
const int INFTY = 100000000;
int d[MAX][MAX]; // distance
char maze[MAX][MAX + 1]; // adjacency matrices

int n, m;
int sx, sy; // start
int gx, gy; // goal

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    queue<P> q;
    q.push(P(sx, sy));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            d[i][j] = INFTY;
        }
    }
    d[sx][sy] = 0;

    while (!q.empty()) {
        P p = q.front();
        q.pop();

        if (p.first == gx && p.second == gy) break;

        for (int i = 0; i < 4; ++i) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (0 <= nx &&
                nx < n &&
                0 <= ny &&
                ny < m &&
                maze[nx][ny] != '#' &&
                d[nx][ny] == INFTY) {
                d[nx][ny] = d[p.first][p.second] + 1;
                q.push(P(nx, ny));
            }
        }
    }

}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%s", maze[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                sx = i;
                sy = j;
            }

            if (maze[i][j] == 'G') {
                gx = i;
                gy = j;
            }
        }
    }

    bfs();

    printf("%d\n", d[gx][gy]);

    return 0;
}

/*
Input:
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#

Output:
22
*/
