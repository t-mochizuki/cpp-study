#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    long W, H, x, y; cin >> W >> H >> x >> y;
    if ((2 * x == W) && (2 * y == H)) {
        cout << (W * H) / 2.0 << " " << 1 << endl;
    } else {
        cout << (W * H) / 2.0 << " " << 0 << endl;
    }
    return 0;
}
