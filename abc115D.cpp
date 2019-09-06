#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

// TODO: RETRY

long a(int N) {
    if (N == 0) return 1;
    else return 2 * a(N - 1) + 3;
}

long p(int N) {
    if (N == 0) return 1;
    else return 2 * p(N - 1) + 1;
}

long f(int N, long X) {
    if (N == 0) {
        if (X <= 0) return 0;
        else return 1;
    } else if (X <= a(N - 1) + 1) {
        return f(N - 1, X - 1);
    } else {
        return p(N - 1) + 1 + f(N - 1, X - 1 - a(N - 1) - 1);
    }
}

int main() {
    int N;
    cin >> N;

    long X;
    cin >> X;

    cout << f(N, X) << endl;

    return 0;
}
