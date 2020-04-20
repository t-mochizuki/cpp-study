#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, B;
    cin >> A >> B;

    if (A + B > 9) {
        cout << "error" << endl;
    } else {
        cout << A + B << endl;
    }

    return 0;
}
