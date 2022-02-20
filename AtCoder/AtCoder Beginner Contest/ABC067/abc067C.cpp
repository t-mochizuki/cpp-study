#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

long abs(long X) {
    return X < 0 ? -X : X;
}

int main() {
    int N;
    cin >> N;

    long a[N];
    REP(0, i, N) {
        cin >> a[i];
    }

    long x = a[0];
    long y = 0;
    REP(1, i, N) {
        y += a[i];
    }

    long ans = abs(x - y);
    REP(1, i, N - 1) {
        x += a[i];
        y -= a[i];
        long z = abs(x - y);

        if (z < ans) {
            ans = z;
        }
    }

    cout << ans << endl;

    return 0;
}
