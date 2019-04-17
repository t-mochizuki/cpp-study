#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    cout << (X - Z) / (Y + Z) << endl;

    return 0;
}
