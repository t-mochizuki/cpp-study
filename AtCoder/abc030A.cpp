#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, B;
    cin >> A >> B;

    float x = B * 1.0 / A;

    cin >> A >> B;
    float y = B * 1.0 / A;

    // cout << "x: " << x << endl;
    // cout << "y: " << y << endl;

    if (x == y) {
        cout << "DRAW" << endl;
    } else if (x > y) {
        cout << "TAKAHASHI" << endl;
    } else {
        cout << "AOKI" << endl;
    }

    return 0;
}
