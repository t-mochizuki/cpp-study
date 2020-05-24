#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    if (n == 3) return true;
    if (n % 3 == 0) return false;

    for (int i = 5; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int X; cin >> X; // 2 <= X <= 1e5

    for (int i = X; i <= 200000; ++i) {
        if (isPrime(i)) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
