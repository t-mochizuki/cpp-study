#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int factorial(int X) {
    int Y = 1;
    REP(1, i, X + 1) {
        Y *= i;
    }
    return Y;
}

int main() {
    int N;
    cin >> N;

    int C[N];
    REP(0, i, N) {
        cin >> C[i];
    }

    int numerator = 0;
    int denominator = factorial(N);
    REP(0, k, denominator) {
        // REP(0, i, N) {
        //     if (i == 0) {
        //         cout << C[i];
        //     } else {
        //         cout << " " << C[i];
        //     }
        // }
        // cout << endl;

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


    // int D[N]; REP(0, i, N) D[i] = 0;
    // REP(0, i, N) {
    //     REP(i + 1, j, N) {
    //         if (C[j] % C[i] == 0) {
    //             cout << i << " " << j << " " << C[i] << " " << C[j] << endl;
    //             D[j]++;
    //         }
    //     }
    // }
    //
    // REP(0, i, N) {
    //     cout << D[i] << endl;
    // }

    // cout << "numerator=" << numerator << endl;
    // cout << "denominator=" << denominator << endl;
    printf("%.6lf\n", 1.0 * numerator / denominator);

    return 0;
}
