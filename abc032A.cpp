#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    while (true) {
        if (n % a == 0 && n % b == 0) {
            break;
        }
        n++;
    }

    printf("%d\n", n);

    return 0;
}
