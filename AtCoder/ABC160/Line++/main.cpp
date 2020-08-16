#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;


template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

template<class T> inline T abs(T X) {
    return X > 0 ? X : -X;
}

void solve() {
    int N, X, Y; cin >> N >> X >> Y;
    int k[N];
    for (int i = 1; i <= N - 1; ++i) {
        k[i] = 0;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            int l = min(abs(j - i), min(abs(X - i) + 1 + abs(j - Y), abs(Y - i) + 1 + abs(j - X)));
            k[l]++;
        }
    }

    for (int i = 1; i <= N - 1; ++i) {
        cout << k[i] << endl;
    }
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
