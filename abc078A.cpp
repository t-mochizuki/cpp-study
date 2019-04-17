#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int X, Y;
    scanf("%x %x", &X, &Y);

    if (X == Y) {
        cout << "=" << endl;
    } else if (X > Y) {
        cout << ">" << endl;
    } else {
        cout << "<" << endl;
    }

    return 0;
}
