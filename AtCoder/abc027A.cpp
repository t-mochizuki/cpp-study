#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int l[3];
    REP(0, i, 3) {
        cin >> l[i];
    }

    if (l[0] == l[1]) {
        cout << l[2] << endl;
        return 0;
    }

    if (l[0] == l[2]) {
        cout << l[1] << endl;
        return 0;
    }

    if (l[1] == l[2]) {
        cout << l[0] << endl;
        return 0;
    }

    return 0;
}
