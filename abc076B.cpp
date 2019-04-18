#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, K;
    cin >> N >> K;

    int ans = 1;
    REP(0, i, N) {
        if (ans < K) {
            ans *= 2;
        } else {
            ans += K;
        }
    }

    cout << ans << endl;

    return 0;
}
