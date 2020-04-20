#include <stdio.h>
#include <iostream>
#include <string>
#include <set>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string s;
    int k;
    cin >> s >> k;

    if (k > s.length()) {
        printf("0\n");
        return 0;
    }

    if (k == s.length()) {
        printf("1\n");
        return 0;
    }

    set<string> ss;
    REP(0, i, s.length() - k + 1) {
        ss.insert(s.substr(i, k));
    }

    // for (set<string>::iterator it = ss.begin(); it != ss.end(); ++it) {
    //     cout << (*it) << endl;
    // }

    printf("%ld\n", ss.size());

    return 0;
}
