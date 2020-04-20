#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string s;
    cin >> s;

    bool b = false;
    for (string::iterator it = s.begin(); it != s.end(); ++it) {
        if (s[0] != (*it)) {
            b = true;
            break;
        }
    }

    if (b) {
        cout << "DIFFERENT" << endl;
    } else {
        cout << "SAME" << endl;
    }

    return 0;
}
