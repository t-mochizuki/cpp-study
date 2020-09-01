#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

void solve(int x) {
    int N; cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int y = 0;
    int c = 0;
    int v = 0;
    for (int i = 0; i < N - 1; ++i) {
        int d = a[i + 1] - a[i];

        if (c == 0) {
            v = d;
        }

        if (v == d) {
            c++;
        } else {
            y = max(y, c);
            c = 1;
            v = d;
        }
    }
    y = max(y, c);
    y++;

    cout << "Case #" << x << ": " << y << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#else
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }
#endif

    return 0;
}
