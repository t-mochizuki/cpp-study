#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string S;
    cin >> S;

    if (S > "2019/04/30") {
        printf("TBD\n");
    } else {
        printf("Heisei\n");
    }

    return 0;
}
