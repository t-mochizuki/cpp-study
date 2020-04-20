#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    long n; cin >> n;

    long ans = 1000000000005;
    for (long a = 1; a <= sqrt(n); ++a) {
        long b = n / a;
        if (a * b == n) {
            long tmp = a + b - 2;
            if (ans > tmp) {
                ans = tmp;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
