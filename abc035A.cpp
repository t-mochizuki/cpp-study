#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int W, H;
    cin >> W >> H;

    if (W == 4 * H / 3) {
        cout << "4:3" << endl;
    } else {
        cout << "16:9" << endl;
    }

    return 0;
}
