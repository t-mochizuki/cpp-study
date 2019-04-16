#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    string W[N];
    REP(0, i, N) {
        cin >> W[i];
    }

    REP(1, i, N) {
        if (W[i - 1][W[i - 1].size() - 1] != W[i][0]) {
            // cout << "W[i]="<< W[i] << endl;
            cout << "No" << endl;
            return 0;
        }
    }

    sort(W, W + N);

    REP(1, i, N) {
        if (W[i - 1] == W[i]) {
            // cout << "W[i]="<< W[i] << endl;
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
