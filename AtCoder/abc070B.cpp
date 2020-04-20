#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int cnt = -1;
    REP(0, i, 101) {
        if (A <= i && i <= B) {
            if (C <= i && i <= D) {
                // cout << "i=" << i << endl;
                cnt++;
            }
        }
    }

    cout << (cnt > 0 ? cnt : 0) << endl;

    return 0;
}
