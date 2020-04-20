#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int H[N];
    REP(0, i, N) {
        cin >> H[i];
    }

    int cnt = 1;
    int height = H[0];
    REP(1, i, N) {
        if (H[i] >= height) {
            cnt++;
            height = H[i];
        }
    }

    cout << cnt << endl;

    return 0;
}
