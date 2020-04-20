#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int n, X; // 1 <= n <= 20, 0 <= X <= 2^20 - 1
    cin >> n >> X;

    int a[n]; // 0 <= a <= 1000
    REP(0, i, n) {
        cin >> a[i];
    }

    // REP(0, i, n) {
    //     cout << i << " : " << ((X >> i) & 0x1) << endl;
    // }

    int b[n];
    REP(0, i, n) {
        b[i] = ((X >> i) & 0x1);
    }

    int ans = 0;
    REP(0, i, n) {
        ans += b[i] == 1 ? a[i] : 0;
    }

    cout << ans << endl;

    return 0;
}
