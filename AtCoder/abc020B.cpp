#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int digit(int n) {
    return n / 10 != 0 ? 1 + digit(n / 10) : 1;
}

int main() {
    int A, B;
    cin >> A >> B;

    int D = digit(B);

    REP(0, i, D) {
        A *= 10;
    }

    cout << 2 * (A + B) << endl;

    return 0;
}
