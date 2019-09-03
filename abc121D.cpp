#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

// 0 = 000
// 1 = 001 g(1) = 0
// 2 = 010 g(2) = 1 XOR g(1) = 001
// 3 = 011 g(3) = 2 XOR g(2) = 011
// 4 = 100 g(4) = 3 XOR g(3) = 000
// 5 = 101 g(5) = 4 XOR g(4) = 100
long g(long x) {
    if (x % 4 == 2) return 1;
    else if (x % 4 == 3) return x;
    else if (x % 4 == 0) return 0;
    else return x - 1;
}

// 3 XOR 5 = 6
// 011 XOR 101 = 110
int main() {
    long A, B;
    cin >> A >> B;

    cout << (g(B + 1) ^ g(A)) << endl;

    return 0;
}
