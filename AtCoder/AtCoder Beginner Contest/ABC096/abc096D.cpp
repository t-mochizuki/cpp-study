#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

bool isPrime(int n) {
    if (n % 2 == 0) return false;
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
    int a[N];

    int cnt = 0;
    int idx = 0;
    while (idx != N) {
        int temp = ((cnt + 1) * 5) + 1;
        if (isPrime(temp)) {
            a[idx] = temp;
            idx++;
        }
        cnt++;
    }

    REP(i, N - 1) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[N - 1]);

    return 0;
}
