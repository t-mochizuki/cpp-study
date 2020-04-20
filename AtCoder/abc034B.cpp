#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << n - 1 << endl;
    } else {
        cout << n + 1 << endl;
    }

    return 0;
}
