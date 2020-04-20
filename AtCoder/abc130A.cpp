#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int X, A; cin >> X >> A;
    if (X < A) {
        cout << 0 << endl;
    } else {
        cout << 10 << endl;
    }
    return 0;
}
