#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string S;
    cin >> S;

    char T = '\0';
    int cnt = 0;
    REP(0, i, S.length()) {
        // cout << S[i] << endl;

        if (i == 0) {
            T = S[i];
        } else {
            if (S[i] != T) {
                T = S[i];
            } else {
                S[i] = T == '0' ? '1' : '0';
                T = S[i];
                cnt++;
            }
        }
    }

    // cout << S << endl;
    cout << cnt << endl;

    return 0;
}
