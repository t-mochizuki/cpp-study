#include <stdio.h>
#include <cmath>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

bool isPrime(int n) {
    if (n == 1) return false;
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

//  n よりも小さい素数の数は何個存在するか
int main() {
    int n; // 10000
    scanf("%d", &n);

    int cnt = 0;
    REP(2, i, n) {
        if (isPrime(i)) cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}
