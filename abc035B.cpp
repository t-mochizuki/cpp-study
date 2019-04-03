#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int abs(int x) {
    return max(x, -x);
}

int main() {
    string S;
    cin >> S;

    int T;
    cin >> T;

    int x = 0;
    int y = 0;
    int cnt = 0;
    REP(0, i, S.length()) {
        if (S[i] == '?') {
            cnt++;
            continue;
        }

        if (S[i] == 'U') {
            y++;
            continue;
        } else if (S[i] == 'D') {
            y--;
            continue;
        } else if (S[i] == 'R') {
            x++;
            continue;
        } else if (S[i] == 'L') {
            x--;
            continue;
        } else {
            return 1;
        }
    }

    int manhattan = abs(x) + abs(y);
    if (T == 1) {
        manhattan += cnt;
    } else {
        manhattan -= cnt;
        if (manhattan < 0) {
            manhattan = abs(manhattan);
            manhattan %= 2;
        }
    }

    cout << manhattan << endl;

    return 0;
}
