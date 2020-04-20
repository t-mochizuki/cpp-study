#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int max(int X, int Y) {
    return X > Y ? X : Y;
}

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int abs(int X) {
    return X > 0 ? X : -X;
}

int main() {
    int N, K; cin >> N >> K;
    int x[N]; REP(0, i, N) cin >> x[i];

    int ans = 1000000000;
    REP(0, i, N - K + 1) {
        // cout << x[i] << ", " << x[i + K - 1] << endl;
        int a = min(abs(x[i]), abs(x[i + K - 1]));
        int b = max(abs(x[i]), abs(x[i + K - 1]));
        if (x[i] >= 0 || x[i + K - 1] < 0) {
            ans = min(ans, b);
        } else {
            ans = min(ans, 2 * a + b);
        }
    }

    cout << ans << endl;

    return 0;
}
