#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int abs(int X, int Y) {
    return X > Y ? X - Y : Y - X;
}

int main() {
    string S;
    cin >> S;

    int ans = 753;
    REP(2, i, S.length()) {
        string s = S.substr(i - 2, 3);
        int X = atoi(s.c_str());
        // cout << X << endl;
        ans = min(abs(X - 753), ans);
    }

    cout << ans << endl;

    return 0;
}
