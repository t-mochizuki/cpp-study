#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int R, G;
    cin >> R >> G;

    cout << 2 * G - R << endl;

    return 0;
}
