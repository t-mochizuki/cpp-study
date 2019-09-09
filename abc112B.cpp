#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int main() {
    int N, T; cin >> N >> T;

    int ans = 1001;
    REP(0, i, N) {
        int c, t; cin >> c >> t;
        if (t <= T) {
            ans = min(ans, c);
        }
    }

    if (ans > 1000) {
        cout << "TLE" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
