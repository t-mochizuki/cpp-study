#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N, M, X, Y; cin >> N >> M >> X >> Y;

    int x[N]; REP(0, i, N) cin >> x[i]; sort(x, x + N, greater<int>());

    int y[M]; REP(0, i, M) cin >> y[i]; sort(y, y + M);

    if (x[0] < y[0] && X < Y && X < y[0] && x[0] < Y) {
        cout << "No War" << endl;
    } else {
        cout << "War" << endl;
    }

    return 0;
}
