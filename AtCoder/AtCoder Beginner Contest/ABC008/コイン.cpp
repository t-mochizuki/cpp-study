#include <stdio.h>
#include <iostream>
#include <algorithm>
// #include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve() {
    int N;
    cin >> N;

    int C[N];
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }

    int S[N];
    for (int i = 0; i < N; ++i) {
        int tmp = 0;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;

            if (C[i] % C[j] == 0) {
                tmp++;
            }
        }
        S[i] = tmp;
        // printf("S[%d]=%d\n", i, S[i]);
    }

    double ans = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] % 2 == 0) {
            ans += 1.0 * (S[i] + 2) / (S[i] * 2 + 2);
        } else {
            ans += 0.5;
        }
    }

    printf("%.6lf\n", ans);
}

int main() {
    // std::ifstream in("AtCoder/ABC008/コイン.input");
    // cin.rdbuf(in.rdbuf());
    // int t; cin >> t;
    // for (int x = 1; x <= t; ++x) {
    //     solve();
    // }

    solve();

    return 0;
}
