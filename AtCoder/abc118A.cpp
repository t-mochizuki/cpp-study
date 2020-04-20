#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, B;
    cin >> A >> B;

    if (B % A == 0) {
        printf("%d\n", A + B);
    } else {
        printf("%d\n", B - A);
    }

    return 0;
}
