#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int K;
    cin >> K;

    if (K % 2 == 0) {
        cout << (K / 2) * (K / 2) << endl;
    } else {
        cout << (K / 2) * (K / 2 + 1) << endl;
    }

    return 0;
}
