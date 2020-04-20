#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

float abs(float X) {
    return X >= 0 ? X : X + 360.0;
}

// 1 50
// 115
int main() {
    int n, m;
    cin >> n >> m;

    int minute = 6 * m;

    n %= 12;

    float hour = 30 * n + 0.5 * m;

    // cout << "hour hand: " << hour << endl;
    // cout << "minute hand: " << minute << endl;

    cout << min(abs(hour - minute), abs(minute - hour)) << endl;

    return 0;
}
