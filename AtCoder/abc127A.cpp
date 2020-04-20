#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, B;
    cin >> A >> B;

    if (A >= 13) {
        cout << B << endl;
    } else if (A >= 6) {
        cout << B / 2 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
