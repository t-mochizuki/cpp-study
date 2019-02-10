#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    if (s == "abc") {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
