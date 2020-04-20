#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;

    if (e - a > k) {
        cout << ":(" << endl;
    } else {
        cout << "Yay!" << endl;
    }

    return 0;
}
