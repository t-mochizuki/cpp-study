#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (A > B && A > C) {
        if (B > C) {
            cout << 1 << endl;
            cout << 2 << endl;
            cout << 3 << endl;
        } else {
            cout << 1 << endl;
            cout << 3 << endl;
            cout << 2 << endl;
        }

        return 0;
    }

    if (B > A && B > C) {
        if (A > C) {
            cout << 2 << endl;
            cout << 1 << endl;
            cout << 3 << endl;
        } else {
            cout << 3 << endl;
            cout << 1 << endl;
            cout << 2 << endl;
        }

        return 0;
    }

    if (C > A && C > B) {
        if (A > B) {
            cout << 2 << endl;
            cout << 3 << endl;
            cout << 1 << endl;
        } else {
            cout << 3 << endl;
            cout << 2 << endl;
            cout << 1 << endl;
        }

        return 0;
    }

    return 0;
}
