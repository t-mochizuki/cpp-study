#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

template<class T> inline T pow(T base, T exponent) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return base * pow(base, exponent - 1);
    } else {
        T tmp = pow(base, exponent / 2);
        return tmp * tmp;
    }
}

void dfs(int index, int N, int* route) {
    if (index == N) {
        for (int i = 0; i < N; ++i) {
            if (i == 0) {
                cout << route[i];
            } else {
                cout << " " << route[i];
            }
        }
        cout << endl;
        return ;
    }

    for (int i = 0; i < 4; ++i) {
        if (i == 0) {
            route[index] = 0;
            dfs(index + 1, N, route);
        } else if (i == 1) {
            route[index] = 1;
            dfs(index + 1, N, route);
        } else if (i == 2) {
            route[index] = 2;
            dfs(index + 1, N, route);
        } else {
            route[index] = 3;
            dfs(index + 1, N, route);
        }
    }
}

void solve() {
    int N, D; cin >> N >> D;
    int X, Y; cin >> X >> Y;

    if (N > 8) {
        terminate();
    }

    int route[N];
    dfs(0, N, route);
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
