#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

float abs(float X, float Y) {
    return X > Y ? X - Y : Y - X;
}

int main() {
    int N;
    cin >> N;

    int T, A;
    cin >> T >> A;

    int H[N];
    REP(0, i, N) {
        cin >> H[i];
    }

    float TT = 0.0, tmp = 1e5 * 0.006;
    int ans = 0;
    REP(0, i, N) {
        TT = T - 0.006 * H[i];
        // cout << "TT = " << TT << endl;
        if (abs(TT, A) < tmp) {
            tmp = abs(TT, A);
            ans = i + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
