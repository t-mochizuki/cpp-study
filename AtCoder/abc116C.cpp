#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int h[N];
    REP(0, i, N) {
        cin >> h[i];
    }

    int k[N];
    REP(0, i, N) {
        if (i == 0) {
            k[0] = h[0];
        } else {
            k[i] = h[i] - h[i - 1];
        }
    }

    int ans = 0;
    REP(0, i, N) {
        if (k[i] > 0) {
            ans += k[i];
        }
    }

    cout << ans << endl;

    return 0;
}
