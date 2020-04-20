#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int p[N];
    REP(0, i, N) {
        cin >> p[i];
    }

    sort(p, p + N);

    int ans = p[N - 1] / 2;
    REP(0, i, N - 1) {
        ans += p[i];
    }

    cout << ans << endl;

    return 0;
}
