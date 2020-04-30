#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

const int DIGIT = 4;

int calc(int x) {
    int b[DIGIT];
    REP(0, i, DIGIT) {
        if (i == 0) {
            b[i] = x;
        } else {
            b[i] = b[i - 1] / 10;
        }
    }

    REP(0, i, DIGIT) {
        b[i] = b[i] % 10;
    }

    int cnt = 0;
    REP(0, i, DIGIT) {
        if (b[i] == 1) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    long N;
    cin >> N;

    if (N > 1000) return 1;

    long xs[N];
    REP(1, i, N + 1) {
        xs[i - 1] = i;
    }

    long cnt = 0;
    REP(0, i, N) {
        cnt += calc(xs[i]);
    }

    cout << cnt << endl;

    return 0;
}
