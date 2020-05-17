#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve(int x) {
    int N; cin >> N;
    int A[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    if (N > 1000) {
        terminate();
    }

    int y = 0;
    for (int i = 1; i <= N; ++i) {
        int V = 0;
        for (int j = i; j <= N; ++j) {
            V += A[j];
            int tmp = sqrt(V);
            if (V == tmp * tmp) {
                y++;
            }
        }
    }

    cout << "Case #" << x << ": " << y << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("KickStart/Round C 2020/Perfect Subarray.input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#else
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#endif

    return 0;
}
