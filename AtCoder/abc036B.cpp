#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    char s[N][N + 1];
    REP(0, i, N) {
        cin >> s[i];
    }

    char t[N][N + 1];
    REP(0, i, N) {
        REP(0, j, N) {
            t[i][j] = s[N - 1 - j][i];
        }
    }

    REP(0, i, N) {
        t[i][N] = '\0';
    }

    REP(0, i, N) {
        cout << t[i] << endl;
    }

    return 0;
}
