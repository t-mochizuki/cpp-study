#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

#define RREP(a, i, n) for (int i = n - 1; i >= a; --i)

int main() {
    int N; // decimal number, 0 <= N <= 2147483647
    cin >> N;

    int b[32];
    REP(0, i, 32) {
        b[i] = ((N >> i) & 0x1);
    }

    cout << N << " : " << "0x";
    RREP(0, i, 32) {
        cout << b[i];
    }
    cout << endl;

    return 0;
}
