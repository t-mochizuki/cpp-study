#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int n; cin >> n;
    int l[n];
    REP(0, i, n) {
        cin >> l[i];
    }

    sort(l, l + n);

    long ans = 0;
    REP(0, i, n) {
        REP(i + 1, j, n) {
            REP (j + 1, k, n) {
                if (l[k] < l[i] + l[j]) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
