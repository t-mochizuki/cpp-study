#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string s;
    cin >> s;

    string t;
    REP(0, i, s.length()) {
        if (i % 2 == 0) {
            t.push_back(s[i]);
        }
    }

    cout << t << endl;

    return 0;
}
