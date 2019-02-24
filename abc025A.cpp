#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string S;
    cin >> S;

    int N;
    cin >> N;
    N--;

    char cx[5 * 5][3];
    REP(0, i, 5) {
        REP(0, j, 5) {
            cx[5 * i + j][0] = S[i];
            cx[5 * i + j][1] = S[j];
            cx[5 * i + j][2] = '\0';
        }
    }

    cout << cx[N] << endl;

    return 0;
}
