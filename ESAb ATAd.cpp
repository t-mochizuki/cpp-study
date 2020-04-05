#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int t, b; cin >> t >> b;
    for (int x = 1; x <= t; ++x) {
        int a[b];
        REP(0, i, 140) {
            cout << 1 << endl;
            cin >> a[0];
        }
        for (int i = 1; i <= b; ++i) {
            cout << i << endl;
            cin >> a[i - 1];
        }
        REP(0, i, b) {
            cout << a[i];
        }
        cout << endl;
        string s;
        cin >> s;
    }
    return 0;
}
