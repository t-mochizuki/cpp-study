#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int X;
    cin >> X;

    cout << (X % 10) + (X / 10) << endl;

    return 0;
}
