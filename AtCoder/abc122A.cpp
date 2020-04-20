#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    char b;
    cin >> b;

    if (b == 'A') cout << 'T' << endl;
    else if (b == 'T') cout << 'A' << endl;
    else if (b == 'C') cout << 'G' << endl;
    else cout << 'C' << endl;

    return 0;
}
