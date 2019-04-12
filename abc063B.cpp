#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string S;
    cin >> S;

    // 97
    // cout << 'a' - 0 << endl;

    int C[26];
    REP(0, i, 26) {
        C[i] = 0;
    }

    REP(0, i, S.length()) {
        C[S[i] - 97]++;

        if(C[S[i] - 97] > 1) {
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;

    return 0;
}
