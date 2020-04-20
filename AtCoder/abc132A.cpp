#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string S; cin >> S;
    sort(S.begin(), S.end());
    if (S[0] == S[1] && S[2] == S[3]) {
        if (S[0] == S[2]) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}
