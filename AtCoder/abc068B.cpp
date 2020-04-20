#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int calc(int i) {
    if (i % 2 == 0) {
        return 1 + calc(i / 2);
    } else {
        return 0;
    }
}

int main() {
    int N;
    cin >> N;

    map<int, int> m;
    REP(1, i, 101) {
        m.insert(make_pair(i, calc(i)));
    }

    int ans = 0;
    int cnt = -1;
    REP(1, i, N + 1) {
        if (m[i] > cnt) {
            ans = i;
            cnt = m[i];
        }
    }

    cout << ans << endl;

    return 0;
}
