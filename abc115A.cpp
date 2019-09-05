#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int D;
    cin >> D;

    switch(D) {
        case 22: cout << "Christmas Eve Eve Eve" << endl; break;
        case 23: cout << "Christmas Eve Eve" << endl; break;
        case 24: cout << "Christmas Eve" << endl; break;
        case 25: cout << "Christmas" << endl; break;
    }

    return 0;
}
