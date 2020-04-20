#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    double x;
    string u;
    double ans = 0.00000;
    REP(0, i, N) {
        cin >> x >> u;

        if (u == "BTC") {
            ans += x * 380000.0;
        } else {
            ans += x;
        }
    }

    printf("%.5f\n", ans);

    return 0;
}
