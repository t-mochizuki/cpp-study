#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int X, A, B;
    cin >> X >> A >> B;

    if (B - A <= 0) {
        cout << "delicious" << endl;
    } else if (B - A <= X) {
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }

    return 0;
}
