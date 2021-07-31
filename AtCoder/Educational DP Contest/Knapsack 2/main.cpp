#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

struct data_t {
    int w, v;
};

int min(int X, int Y) {
    return X < Y ? X : Y;
}

void solve() {
    int N, w; cin >> N >> w; // N <= 100, w <= 1e9
    data_t I[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> I[i].w; // w <= 1e9
        cin >> I[i].v; // v <= 1000
    }

    long W[N + 1][100000 + 1];

    for (int v = 0; v <= 100000; ++v) {
        W[0][v] = 100000000001; // 1e9 * 100 + 1
    }

    for (int i = 1; i <= N; ++i) {
        for (int v = 0; v <= 100000; ++v) {
            if (I[i].v >= v) {
                W[i][v] = min(I[i].w, W[i - 1][v]);
            } else {
                W[i][v] = min(W[i - 1][v], W[i - 1][v - I[i].v] + I[i].w);
            }
        }
    }

    // DEBUG
    // for (int i = 1; i <= N; ++i) {
    //     for (int v = 29; v <= 51; ++v) {
    //         if (v == 29) {
    //             cout << W[i][v];
    //         } else {
    //             cout << " " << W[i][v];
    //         }
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int v = 0; v <= 100000; ++v) {
            if (W[i][v] > w) break;
            ans = max(ans, v);
        }
    }

    cout << ans << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("input");
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
