#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string S;
    cin >> S;

    int len = S.length();

    string T = "";
    REP(0, i, len - 1) {
        S = S.substr(0, S.length() - 1);
        // cout << "S=" << S << endl;

        if (S.length() % 2 != 0) {
            continue;
        }

        string lhs = S.substr(0, S.length() / 2);
        string rhs = S.substr(S.length() / 2);
        if (lhs == rhs) {
            T = S;
            break;
            // cout << "T=" << T << endl;
        }
    }

    cout << T.length() << endl;

    return 0;
}
