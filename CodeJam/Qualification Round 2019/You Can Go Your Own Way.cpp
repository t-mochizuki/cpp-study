#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int T;
    cin >> T;

    REP(0, i, T) {
        int N;
        cin >> N;

        string P; // 2N - 2
        cin >> P;

        string S;
        REP(0, j, P.length()) {
            if (P[j] == 'S') {
                S.push_back('E');
            } else {
                S.push_back('S');
            }
        }

        printf("Case #%d: %s\n", i + 1, S.c_str());
    }

    return 0;
}
