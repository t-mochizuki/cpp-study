#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, D;
    cin >> A >> D;

    printf("%d\n", max((A + 1) * D, A * (D + 1)));

    return 0;
}
