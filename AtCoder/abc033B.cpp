#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    string S[N];
    int P[N];
    REP(0, i, N) {
        cin >> S[i] >> P[i];
    }

    int total = 0;
    REP(0, i, N) {
        total += P[i];
    }

    int half = 0;
    half = total / 2;

    REP(0, i, N) {
        if (P[i] > half) {
            cout << S[i] << endl;
            return 0;
        }
    }

    cout << "atcoder" << endl;

    return 0;
}
