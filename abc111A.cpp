#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string n; cin >> n;

    REP(0, i, n.length()) {
        if (n[i] == '1') {
            n[i] = '9';
        } else {
            n[i] = '1';
        }
    }

    cout << n << endl;

    return 0;
}
