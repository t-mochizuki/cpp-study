#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string S; cin >> S;

    if (S[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }

    if (S[1] <= 'Z' || S[S.length() - 1] <= 'Z') {
        cout << "WA" << endl;
        return 0;
    }

    sort(S.begin(), S.end());

    if (S[1] != 'C') {
        cout << "WA" << endl;
        return 0;
    }

    if (S[2] <= 'Z') {
        cout << "WA" << endl;
        return 0;
    }

    cout << "AC" << endl;

    return 0;
}
