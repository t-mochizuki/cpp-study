#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;

    cout << (H - h) * (W - w) << endl;

    return 0;
}
