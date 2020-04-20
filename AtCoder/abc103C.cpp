#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int A;
    int ans = 0;
    REP(0, i, N) {
        cin >> A;
        ans += A;
    }

    cout << ans - N << endl;

    return 0;
}
