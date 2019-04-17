#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int A[4];
    REP(0, i, 4) {
        A[i] = N % 10;
        N /= 10;
    }

    REP(0, i, 2) {
        int cnt = 0;

        REP(i, j, i + 2) {
            if (A[j] == A[j + 1]) {
                cnt++;
            }
        }

        if (cnt == 2) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
