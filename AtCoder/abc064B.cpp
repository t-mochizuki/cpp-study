#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    int a[N];
    REP(0, i, N) {
        cin >> a[i];
    }

    sort(a, a + N);

    cout << a[N - 1] - a[0] << endl;

    return 0;
}
