#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int a[N];
    REP(0, i, N) {
        cin >> a[i];
        a[i]--; // zero origin
    }

    int b[N];
    REP(0, i, N) {
        b[i] = 0;
    }

    int i = 0;
    while (true) {
        if (b[i] == 1) {
            cout << -1 << endl;
            return 0;
        }

        b[i] = 1;

        if (a[i] == 1) {
            break;
        }

        i = a[i];
    }

    int cnt = 0;
    REP(0, i, N) {
        // cout << i << ' ' << b[i] << endl;
        cnt += b[i];
    }

    cout << cnt << endl;

    return 0;
}
