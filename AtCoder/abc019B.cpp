#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string s;
    cin >> s;

    int cnt = 1;
    REP(0, i, s.length()) {
        if (s[i] == s[i + 1]) {
            cnt++;
        } else {
            cout << s[i] << cnt;
            cnt = 1;
        }
    }

    cout << endl;

    return 0;
}
