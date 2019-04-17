#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

// rotate matrix
// cosθ -sinθ
// sinθ cosθ

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int dx = x2 - x1;
    int dy = y2 - y1;

    // rotate counterclockwise by 90 degrees
    int rotate_by_90_degrees[2][2] = {
        {0, -1},
        {1, 0}
    };

    int x3 = rotate_by_90_degrees[0][0] * dx + rotate_by_90_degrees[0][1] * dy;
    int y3 = rotate_by_90_degrees[1][0] * dx + rotate_by_90_degrees[1][1] * dy;

    cout << x3 << " " << y3 << endl;

    int rotate_by_180_degrees[2][2] = {
        {-1, 0},
        {0, -1}
    };

    int x4 = rotate_by_180_degrees[0][0] * dx + rotate_by_180_degrees[0][1] * dy;
    int y4 = rotate_by_180_degrees[1][0] * dx + rotate_by_180_degrees[1][1] * dy;

    cout << x4 << " " << y4 << endl;

    int rotate_by_270_degrees[2][2] = {
        {0, 1},
        {-1, 0}
    };

    int x5 = rotate_by_270_degrees[0][0] * dx + rotate_by_270_degrees[0][1] * dy;
    int y5 = rotate_by_270_degrees[1][0] * dx + rotate_by_270_degrees[1][1] * dy;

    cout << x5 << " " << y5 << endl;

    return 0;
}
