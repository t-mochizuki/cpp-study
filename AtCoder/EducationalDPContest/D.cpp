#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

struct data_t {
    int w, v;
};

data_t I[101];

// 太郎君が持ち帰る品物の価値の総和の最大値
long V[101][100001];

int max(int X, int Y) {
    return X > Y ? X : Y;
}

int main() {
    int N, W; cin >> N >> W; // N <= 100, W <= 100000
    for (int i = 1; i <= N; ++i) {
        cin >> I[i].w;
        cin >> I[i].v;
    }

    for (int w = 0; w <= W; ++w) {
        V[0][w] = 0;
    }
    for (int i = 0; i <= N; ++i) {
        V[i][0] = 0;
    }
    for (int i = 1; i <= N; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (w >= I[i].w) {
                V[i][w] = max(V[i - 1][w], V[i - 1][w - I[i].w] + I[i].v);
            } else {
                V[i][w] = V[i - 1][w];
            }
        }
    }

    // DEBUG
    // for (int i = 1; i <= N; ++i) {
    //     for (int w = 0; w <= W; ++w) {
    //         if (w == 0) {
    //             cout << V[i][w];
    //         } else {
    //             cout << " " << V[i][w];
    //         }
    //     }
    //     cout << endl;
    // }

    cout << V[N][W] << endl;

    return 0;
}
