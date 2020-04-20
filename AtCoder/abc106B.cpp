#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    if (N < 105) {
        cout << 0 << endl;
    } else if (N < 135) {
        cout << 1 << endl;
    } else if (N < 165) {
        cout << 2 << endl;
    } else if (N < 189) {
        cout << 3 << endl;
    } else if (N < 195) {
        cout << 4 << endl;
    } else {
        cout << 5 << endl;
    }

    return 0;
}
