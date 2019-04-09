#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, K;
    cin >> N >> K;

    long a[N];
    REP(0, i, N) {
        cin >> a[i];
    }

    long ans = 0;
    REP(0, i, N - K + 1) {
        REP(i, j, i + K) {
            ans += a[j];
        }
    }

    cout << ans << endl;

    return 0;
}
