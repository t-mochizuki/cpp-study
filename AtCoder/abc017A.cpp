#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int s, e;
    int ans = 0;

    REP(0, i, 3) {
        cin >> s >> e;
        ans += s * e / 10;
    }

    cout << ans << endl;

    return 0;
}
