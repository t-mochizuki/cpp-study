#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int x, y;
    cin >> x >> y;

    if (y > x) {
        cout << "Better" << endl;
    } else {
        cout << "Worse" << endl;
    }

    return 0;
}
