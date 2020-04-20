#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string N;
    cin >> N;

    string R = N;
    reverse(R.begin(), R.end());

    REP(0, i, N.length()) {
        if (N[i] != R[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
