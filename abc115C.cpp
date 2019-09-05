#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, K;
    cin >> N >> K;

    long h[N];
    REP(0, i, N) {
        cin >> h[i];
    }

    sort(h, h + N);

    // REP(0, i, N - K + 1) {
    //     cout << h[i] << " " << h[i + K - 1] << endl;
    // }

    long ans = 1000000000;
    REP(0, i, N - K + 1) {
        ans = min(ans, h[i + K - 1] - h[i]);
    }

    cout << ans << endl;

    return 0;
}
