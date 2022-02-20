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

template<class T> inline T pow(T base, T exponent) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return base * pow(base, exponent - 1);
    } else {
        T tmp = pow(base, exponent / 2);
        return tmp * tmp;
    }
}

template<class T> inline T abs(T X) {
    return X > 0 ? X : -X;
}

void solve() {
    int N; cin >> N;
    int X[N];
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    int ans = 1000005;
    for (int P = 1; P <= 100; ++P) {
        int tmp = 0;
        for (int i = 0; i < N; ++i) {
            tmp += pow(abs(X[i] - P), 2);
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
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
