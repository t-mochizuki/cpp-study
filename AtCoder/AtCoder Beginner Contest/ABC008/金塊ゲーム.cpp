#include <stdio.h>
#include <iostream>
#include <algorithm>
// #include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::next_permutation;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

int factorial(int X) {
    int Y = 1;
    for (int i = 1; i <= X; ++i) {
        Y *= i;
    }
    return Y;
}

int operate(int W, int H, int N, int *X, int *Y, int *xs) {
    int plane[W + 1][H + 1];
    for (int i = 1; i <= W; ++i) {
        for (int j = 1; j <= H; ++j) {
            plane[i][j] = 1;
        }
    }

    int cnt = 0;
    for (int j = 0; j < N; ++j) {
        int x, y;
        x = X[xs[j]]; y = Y[xs[j]];
        plane[x][y] = 0;
        cnt++;

        // east
        for (int i = x + 1; i <= W; ++i) {
            if (plane[i][y] == 0) {
                break;
            } else {
                plane[i][y] = 0;
                cnt++;
            }
        }

        // west
        for (int i = x - 1; i >= 1; --i) {
            if (plane[i][y] == 0) {
                break;
            } else {
                plane[i][y] = 0;
                cnt++;
            }
        }

        // south
        for (int i = y - 1; i >= 1; --i) {
            if (plane[x][i] == 0) {
                break;
            } else {
                plane[x][i] = 0;
                cnt++;
            }
        }

        // north
        for (int i = y + 1; i <= H; ++i) {
            if (plane[x][i] == 0) {
                break;
            } else {
                plane[x][i] = 0;
                cnt++;
            }
        }
    }

    return cnt;
}

void solve() {
    int W, H, N; cin >> W >> H >> N;

    int X[N + 1], Y[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> X[i] >> Y[i];
    }

    if (N > 8 || W > 80 || H > 80) {
        terminate();
    } else {
        int xs[N];
        for (int i = 1; i <= N; ++i) {
            xs[i - 1] = i;
        }

        int ans = 0;
        for (int i = 0; i < factorial(N); ++i) {
            // for (int j = 0; j < N; ++j) {
            //     if (j == 0) cout << xs[j];
            //     else cout << " " << xs[j];
            // }
            // cout << endl;

            ans = max(ans, operate(W, H, N, X, Y, xs));

            next_permutation(xs, xs + N);
        }

        cout << ans << endl;
    }
}

int main() {
    // std::ifstream in("AtCoder/ABC008/金塊ゲーム.input");
    // cin.rdbuf(in.rdbuf());
    // int t; cin >> t;
    // for (int x = 1; x <= t; ++x) {
    //     solve();
    // }

    solve();

    return 0;
}
