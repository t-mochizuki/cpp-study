#include <stdio.h>
#include <iostream>
#include <cmath>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

// void dfs(int index, int N, int* route) {
//     if (index == N) {
//         for (int i = 0; i < N; ++i) {
//             if (i == 0) {
//                 cout << route[i];
//             } else {
//                 cout << " " << route[i];
//             }
//         }
//         cout << endl;
//         return ;
//     }
//     for (int i = 0; i < 4; ++i) {
//         if (i == 0) {
//             route[index] = 0;
//             dfs(index + 1, N, route);
//         } else if (i == 1) {
//             route[index] = 1;
//             dfs(index + 1, N, route);
//         } else if (i == 2) {
//             route[index] = 2;
//             dfs(index + 1, N, route);
//         } else {
//             route[index] = 3;
//             dfs(index + 1, N, route);
//         }
//     }
// }

const int LIMIT = 100;
long memo[LIMIT + 1][2 * LIMIT + 1][2 * LIMIT + 1];

long dfs(int N, int X, int Y, int count, int posX, int posY) {
    if (memo[count][posX][posY] != -1) {
        return memo[count][posX][posY];
    }

    if (count == N) {
        if (X == posX && Y == posY) {
            return memo[count][posX][posY] = 1;
        } else {
            return memo[count][posX][posY] = 0;
        }
    }

    long ret = 0;
    for (int i = 0; i < 4; ++i) {
        if (i == 0) {
            ret += dfs(N, X, Y, count + 1, posX, posY + 1);
        } else if (i == 1) {
            ret += dfs(N, X, Y, count + 1, posX + 1, posY);
        } else if (i == 2) {
            ret += dfs(N, X, Y, count + 1, posX, posY - 1);
        } else {
            ret += dfs(N, X, Y, count + 1, posX - 1, posY);
        }
    }
    return memo[count][posX][posY] = ret;
}

void solve() {
    int N, D; cin >> N >> D;
    int X, Y; cin >> X >> Y;

    if (N > LIMIT) {
        terminate();
    }

    for (int count = 0; count < LIMIT + 1; ++count) {
        for (int posX = 0; posX < 2 * LIMIT + 1; ++posX) {
            for (int posY = 0; posY < 2 * LIMIT + 1; ++posY) {
                memo[count][posX][posY] = -1;
            }
        }
    }

    if (X % D == 0 && Y % D == 0) {
        X = X / D;
        Y = Y / D;
        double ans = dfs(N, X + N, Y + N, 0, N, N) * 1.0 * pow(0.25, N);
        printf("%.10f\n", ans);
    } else {
        cout << 0.0 << endl;
    }

}

int main() {

#ifdef DEV
    std::ifstream in("AtCoder/ABC011/大ジャンプ.input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
