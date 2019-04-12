#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string s;
    cin >> s;

    cout << s[0] << s.length() - 2 << s[s.length() - 1] << endl;

    return 0;
}
