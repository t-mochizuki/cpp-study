#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, K;
    cin >> N >> K;

    int l[N];
    REP(0, i, N) {
        cin >> l[i];
    }

    sort(l, l + N, greater<int>());

    int ans = 0;
    REP(0, i, K) {
        ans += l[i];
    }

    cout << ans << endl;

    return 0;
}
