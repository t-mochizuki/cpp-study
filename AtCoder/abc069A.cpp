#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int n, m;
    cin >> n >> m;

    cout << --n * --m << endl;

    return 0;
}
