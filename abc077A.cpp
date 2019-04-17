#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    char C[2][4];
    cin >> C[0] >> C[1];

    // cout << C[0] << endl;
    // cout << C[1] << endl;

    if (C[0][0] == C[1][2] && C[0][1] == C[1][1] && C[0][2] == C[1][0]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
