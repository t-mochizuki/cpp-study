#include <stdio.h>
#include <cmath>

using namespace std;

#define REP(a, i, n) for (int i = a; i <= n; ++i)

const int MAX_N = 1e6 - 1;
bool memo[MAX_N + 1];

bool isPrime(int n) {
    if (memo[n]) return true;

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

    memo[n] = true;
    return true;
}

//  n よりも小さい素数の数は何個存在するか
int main() {

    REP(0, i, MAX_N) {
        memo[i] = false;
    }

    int n = 0; // 999,999
    while(scanf("%d", &n) != EOF) {
        int cnt = 0;
        REP(1, i, n) {
            if (isPrime(i)) cnt++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}

