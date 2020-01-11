#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, P;
    cin >> A >> P;

    cout << (3 * A + P) / 2 << endl;
    return 0;
}
