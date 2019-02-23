#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string X;
    cin >> X;

    for (int i = 0; i != X.length();) {
        if (X[i] == 'c' && X[i + 1] == 'h') {
            i += 2;
            continue;
        }

        if (X[i] == 'o') {
            i++;
            continue;
        }

        if (X[i] == 'k') {
            i++;
            continue;
        }

        if (X[i] == 'u') {
            i++;
            continue;
        }

        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}
