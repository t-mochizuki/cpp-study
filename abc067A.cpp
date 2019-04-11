#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, B;
    cin >> A >> B;

    if (A % 3 == 0) {
        cout << "Possible" << endl;
    } else if (B % 3 == 0) {
        cout << "Possible" << endl;
    } else if ((A + B) % 3 == 0) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
