#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve() {
    int n; cin >> n;
    char s[n + 1]; cin >> s;

    int nR = 0;
    int nG = 0;
    int nB = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') {
            nR++;
        } else if (s[i] == 'G') {
            nG++;
        } else if (s[i] == 'B') {
            nB++;
        } else {
        }
    }

    long w = nR * nG * nB;

    long z = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int k = 2 * j - i;
            if (k < n) {
                if (s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) {
                    z++;
                }
            }
        }
    }

    cout << w - z << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("AtCoder/ABC162/RGB Triplets.input");
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
