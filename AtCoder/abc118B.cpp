#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, M;
    cin >> N >> M;

    int A[M];
    REP(0, i, M) {
        A[i] = 0;
    }

    REP(0, i, N) {
        int K;
        cin >> K;

        REP(0, j, K) {
            int x;
            cin >> x;
            x--;
            A[x]++;
        }
    }

    // REP(0, i, M) {
    //     cout << A[i] << endl;
    // }

    int cnt = 0;
    REP(0, i, M) {
        // cout << A[i] << endl;
        if (A[i] == N) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
