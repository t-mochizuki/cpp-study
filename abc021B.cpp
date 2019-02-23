#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int a, b;
    cin >> a >> b;

    int K;
    cin >> K;

    int P[K];
    REP(0, i, K) {
        cin >> P[i];
    }

    sort(P, P + K);

    REP(0, i, K) {
        if (a == P[i] || b == P[i]) {
            cout << "NO" << endl;
            return 0;
        }

        if (i != 0 && P[i - 1] == P[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
