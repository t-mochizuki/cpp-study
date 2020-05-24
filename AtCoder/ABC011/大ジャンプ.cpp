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

long dfs(int index, int N, int D, int X, int Y, int posX, int posY) {
    if (index == N) {
        if (X == posX && Y == posY) {
            return 1;
        } else {
            return 0;
        }
    }

    long count = 0;
    for (int i = 0; i < 4; ++i) {
        if (i == 0) {
            count += dfs(index + 1, N, D, X, Y, posX, posY + D);
        } else if (i == 1) {
            count += dfs(index + 1, N, D, X, Y, posX + D, posY);
        } else if (i == 2) {
            count += dfs(index + 1, N, D, X, Y, posX, posY - D);
        } else {
            count += dfs(index + 1, N, D, X, Y, posX - D, posY);
        }
    }
    return count;
}

void solve() {
    int N, D; cin >> N >> D;
    int X, Y; cin >> X >> Y;

    if (N > 8) {
        terminate();
    }

    cout << dfs(0, N, D, X, Y, 0, 0) * 1.0 * pow(0.25, N) << endl;
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
