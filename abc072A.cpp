#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int X, t;
    cin >> X >> t;

    int res = X - t;

    cout << (res > 0 ? res : 0) << endl;

    return 0;
}
