#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int max(int X, int Y) {
    return X > Y ? X : Y;
}

int main() {
    int A, B, C; cin >> A >> B >> C;

    cout << max(max(A * 10 + B + C, A + B * 10 + C), A + B + C * 10) << endl;

    return 0;
}
