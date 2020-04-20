#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int check[9];
    REP(0, i, 9) {
        check[i] = 0;
    }

    REP(0, i, N) {
        int a;
        cin >> a;

        if (a < 3200) {
            check[a / 400] = 1;
        } else {
            check[8]++;
        }
    }

    int cnt = 0;
    REP(0, i, 8) {
        cnt += check[i];
    }

    if (cnt == 0) {
        cout << 1 << ' ' << check[8] << endl;
    } else {
        cout << cnt << ' ' << cnt + check[8] << endl;
    }

    return 0;
}
