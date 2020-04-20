#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N;
    cin >> N;

    // 一の位は9
    if (N % 10 == 9) {
        cout << "Yes" << endl;
        return 0;
    }

    N /= 10;

    // 十の位は9
    if (N % 10 == 9) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

    return 0;
}
