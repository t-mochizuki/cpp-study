#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int T;
    cin >> T;

    REP(0, i, T) {
        string N;
        cin >> N;

        char A[105], B[105];
        int tmp = -1;
        REP(0, j, N.length()) {
            if (N[j] == '4') {
                A[j] = '2';
                B[j] = '2';
                if (tmp == -1) {
                    tmp = j;
                }
            } else {
                A[j] = N[j];
                B[j] = '0';
            }
        }
        A[N.length()] = '\0';

        REP(tmp, j, N.length()) {
            B[j - tmp] = B[j];
        }
        B[N.length() - tmp] = '\0';


        printf("Case #%d: %s %s\n", i + 1, A, B);
    }

    return 0;
}
