#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

long solve(long N) {
    if (5 > N) return 0;
    else return N / 5 + solve(N / 5);
}

int main() {
    long N; cin >> N;
    if (N % 2 == 1) {
        cout << 0 << endl;
    } else {
        cout << solve(N / 2) << endl;
    }
    return 0;
}
