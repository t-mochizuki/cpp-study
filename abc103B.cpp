#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

string rotate(string S) {
    return S.substr(S.size() - 1) + S.substr(0, S.size() - 1);
}

int main() {
    string S;
    cin >> S;

    string T;
    cin >> T;

    REP(0, i, S.size()) {
        if (S == T) {
            cout << "Yes" << endl;
            return 0;
        } else {
            S = rotate(S);
        }
    }

    cout << "No" << endl;

    return 0;
}
