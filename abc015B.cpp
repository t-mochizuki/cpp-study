#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int A = 0, ans = 0, cnt = 0;
    REP(0, i, N) {
        cin >> A;

        ans += A;

        if (A != 0) {
            cnt++;
        }
    }

    ans = (ans + cnt - 1) / cnt;

    cout << ans << endl;

    return 0;
}
