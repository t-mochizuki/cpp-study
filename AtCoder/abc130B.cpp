#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, X; cin >> N >> X;
    int L[N];
    REP(0, i, N) cin >> L[i];

    int ans = 1;
    int D = 0;
    REP(0, i, N) {
        D += L[i];
        if (D <= X) {
            ans++;
        } else {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
