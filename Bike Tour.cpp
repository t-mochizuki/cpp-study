#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        int n; cin >> n;
        int h[n];
        REP(0, i, n) {
            cin >> h[i];
        }

        int y = 0;
        REP(0, i, n) {
            if (i == 0) {
                continue;
            } else if (i == n - 1) {
                continue;
            }

            if (h[i - 1] < h[i] && h[i] > h[i + 1]) {
                y++;
            }
        }

        cout << "Case #" << x << ": " << y << endl;
    }

    return 0;
}
