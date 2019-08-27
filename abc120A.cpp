#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (B / A > C) {
        printf("%d\n", C);
    } else {
        printf("%d\n", B / A);
    }

    return 0;
}
