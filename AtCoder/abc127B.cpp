#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int r, D, x;
    cin >> r >> D >> x;

    REP(0, i, 10) {
        x = r * x - D;
        cout << x << endl;
    }
    return 0;
}
