#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

void solve() {
    int N, K; cin >> N >> K;
    string S; cin >> S;

    int ans = 0;

    for (int l = 0; l < N; ++l) {
        if (l != 0 && S[l - 1] == S[l]) {
            continue;
        }

        int count = 0;
        int tmp = 0;
        for (int r = l; r < N; ++r) {
            if (l == r) {
            } else if (S[r - 1] != S[r]) {
                count++;
            }

            if (S[l] == '0') {
                if (count <= 2 * K - 1) {
                    tmp = r - l + 1;
                }
            } else {
                if (count <= 2 * K) {
                    tmp = r - l + 1;
                }
            }
        }

        ans = max(ans, tmp);
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
