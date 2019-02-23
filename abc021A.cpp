#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int pow(int x, int n) {
    return n == 0 ? 1 : x * pow(x, n - 1);
}

int main() {
    int N;
    cin >> N;

    int b[4];
    int cnt = 0;
    REP(0, i, 4) {
        b[i] = ((N >> i) & 0x1);

        if (b[i] == 1) {
            cnt++;
        }
    }

    cout << cnt << endl;

    REP(0, i, 4) {
        if (b[i] == 1) {
            cout << pow(2, i) << endl;
        }
    }

    return 0;
}
