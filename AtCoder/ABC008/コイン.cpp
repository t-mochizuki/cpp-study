#include <stdio.h>
#include <iostream>
#include <algorithm>
// #include <fstream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

// 階乗
int factorial(int X) {
    int Y = 1;
    REP(1, i, X + 1) {
        Y *= i;
    }
    return Y;
}

void solve() {
    int N;
    cin >> N;

    int C[N];
    REP(0, i, N) {
        cin >> C[i];
    }

    int numerator = 0;
    int denominator = factorial(N);
    REP(0, k, denominator) {
        int D[N]; REP(0, i, N) D[i] = 0;
        REP(0, i, N) {
            REP(i + 1, j, N) {
                if (C[j] % C[i] == 0) {
                    D[j]++;
                }
            }
        }

        REP(0, i, N) {
            if (D[i] % 2 == 0) {
                numerator++;
            }
        }

        next_permutation(C, C + N);
    }

    printf("%.6lf\n", 1.0 * numerator / denominator);
}

int main() {
    // std::ifstream in("AtCoder/ABC008/コイン.input");
    // cin.rdbuf(in.rdbuf());
    //
    // int t; cin >> t;
    // for (int x = 1; x <= t; ++x) {
    //     solve();
    // }

    solve();

    return 0;
}
