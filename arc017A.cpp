#include <stdio.h>
#include <cmath>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

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
    int N;
    scanf("%d", &N);

    if (isPrime(N)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
