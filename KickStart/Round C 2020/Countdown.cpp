#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve(int x) {
    int N, K; cin >> N >> K;
    int A[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int y = 0;
    for (int i = 1; i <= N - K + 1; ++i) {
        bool ok = true;
        int before = K;
        for (int j = 0; j < K; ++j) {
            if (before != A[i + j]) {
                ok = false;
                break;
            }

            before--;
        }

        if (ok) {
            y++;
        }
    }

    cout << "Case #" << x << ": " << y << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("KickStart/Round C 2020/Countdown.input");
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
