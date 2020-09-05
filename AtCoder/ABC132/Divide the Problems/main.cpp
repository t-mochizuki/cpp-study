#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N; cin >> N;
    int d[N]; REP(0, i, N) cin >> d[i];

    sort(d, d + N);

    // cout << d[N / 2 - 1] << endl;
    // cout << d[N / 2] << endl;

    cout << d[N / 2] - d[N / 2 - 1] << endl;
    return 0;
}
