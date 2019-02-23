#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (A + B == C) {
        if (A - B == C) {
            cout << "?" << endl;
        } else {
            cout << "+" << endl;
        }
    } else {
        if (A - B == C) {
            cout << "-" << endl;
        } else {
            cout << "!" << endl;
        }
    }

    return 0;
}
