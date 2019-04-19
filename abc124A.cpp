#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, B;
    cin >> A >> B;

    int ans = 0;
    ans += A > B ? A-- : B--;
    ans += A > B ? A-- : B--;

    cout << ans << endl;

    return 0;
}
