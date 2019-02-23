#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    if (N % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    if (S[N / 2] != 'b') {
        cout << -1 << endl;
        return 0;
    }

    REP(0, i, N / 2) {
        if (S[i] == 'a' && S[S.length() - 1 - i] == 'c') {
            continue;
        }

        if (S[i] == 'c' && S[S.length() - 1 - i] == 'a') {
            continue;
        }

        if (S[i] == 'b' && S[S.length() - 1 - i] == 'b') {
            continue;
        }

        cout << -1 << endl;
        return 0;
    }

    cout << N / 2 << endl;

    return 0;
}
