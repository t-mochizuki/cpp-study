#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string S[12];
    REP(0, i, 12) {
        cin >> S[i];
    }

    int cnt = 0;
    REP(0, i, 12) {
        REP(0, j, S[i].size()) {
            if (S[i][j] == 'r') {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
