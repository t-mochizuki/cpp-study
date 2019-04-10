#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a > b) {
        if (a > c) {
            cout << b + c << endl; // maximum = a
        } else {
            cout << b + a << endl; // maximum = c
        }
    } else {
        if (b > c) {
            cout << a + c << endl; // maximum = b
        } else {
            cout << a + b << endl; // maximum = c
        }
    }

    return 0;
}
