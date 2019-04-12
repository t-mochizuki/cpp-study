#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int l, r;
    int cnt = 0;
    REP(0, i, N) {
        cin >> l >> r;
        cnt += r - l + 1;
    }

    cout << cnt << endl;

    return 0;
}
