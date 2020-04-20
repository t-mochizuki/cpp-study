#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// TODO: RETRY

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string N; cin >> N;

    char c = '0' - 0;
    REP(0, i, N.length()) {
        if (N[i] > c) {
            c = N[i];
        }
    }

    REP(0, i, N.length()) {
        N[i] = c;
    }

    cout << N << endl;

    return 0;
}
