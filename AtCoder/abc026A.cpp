#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A;
    cin >> A;

    cout << (A / 2) * (A - A / 2) << endl;

    return 0;
}
