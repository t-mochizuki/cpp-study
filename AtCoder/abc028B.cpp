#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string S;
    cin >> S;

    int X[6];
    REP(0, i, 6) {
        X[i] = 0;
    }

    REP(0, i, S.size()) {
        if ('A' == S[i]) {
            X[0]++;
            continue;
        }
        if ('B' == S[i]) {
            X[1]++;
            continue;
        }
        if ('C' == S[i]) {
            X[2]++;
            continue;
        }
        if ('D' == S[i]) {
            X[3]++;
            continue;
        }
        if ('E' == S[i]) {
            X[4]++;
            continue;
        }
        if ('F' == S[i]) {
            X[5]++;
            continue;
        }
    }

    cout << X[0] << " ";
    cout << X[1] << " ";
    cout << X[2] << " ";
    cout << X[3] << " ";
    cout << X[4] << " ";
    cout << X[5] << endl;

    return 0;
}
