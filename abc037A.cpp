#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (A < B) {
        cout << C / A << endl;
    } else {
        cout << C / B << endl;
    }

    return 0;
}
