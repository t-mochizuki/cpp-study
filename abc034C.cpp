#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int dp(int a, int b) {
    if (a == 1 || b == 1) {
        return 1;
    }

    return (dp(a - 1, b) + dp(a, b - 1)) % 1000000007;
}

int main() {
    int W, H;
    cin >> W >> H;

    cout << dp(W, H) << endl;

    return 0;
}
