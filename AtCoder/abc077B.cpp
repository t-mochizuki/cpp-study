#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int ans = 0;
    REP(0, i, 100000) {
        if (i * i <= N) {
            ans = i * i;
        } else {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
