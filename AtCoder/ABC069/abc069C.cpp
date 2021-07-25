#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int ai;
    int cnt4 = 0;
    int cnte = 0;
    int cnto = 0;
    REP(0, i, N) {
        cin >> ai;

        if (ai % 4 == 0) {
            cnt4++;
            continue;
        }

        if (ai % 2 == 0) {
            cnte++;

            if (cnte % 2 == 0) {
                cnte--;
            }

            continue;
        }

        cnto++;
    }

    // cout << "N=" << N << endl;
    // cout << "cnt4=" << cnt4 << endl;
    // cout << "cnto=" << cnto << endl;
    // cout << "cnte=" << cnte << endl;
    if (cnte + cnto - cnt4 > 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}
