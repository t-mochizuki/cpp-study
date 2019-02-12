#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string W;
    cin >> W;

    string V = "";
    for (string::iterator it = W.begin(); it != W.end(); ++it) {
        if (*it != 'a' && *it != 'i' && *it != 'u' && *it != 'e' && *it != 'o') {
            V += *it;
        }
    }

    printf("%s\n", V.c_str());

    return 0;
}
